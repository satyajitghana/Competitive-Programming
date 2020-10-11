import math
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if(len(prices)<1 or k==0):return 0
    
        #when the number of transaction exceeds the length of prices ,the solution will be simply 
		#maximum profit earned using the maximum possible transactions 
		
        if(2*k>len(prices)):
            #the above method can be used for solving https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ problem  
			s1=-prices[0]
            s2=0
            for i in range(1,len(prices)):
                s1=max(s1,s2-prices[i])
                s2=max(s2,s1+prices[i])
            return s2
        
		# maintaining a state array 
		states=[]
		
        for i in range(2*k):
            if(i==0):
                states.append(-prices[0])
            elif(i%2!=0):
                states.append(0)
            else:
                states.append(-math.inf)
                

        for i in range(1,len(prices)):
              for j in range(2*k):
                if(j==0):
                   states[j]=max(states[j],-prices[i])
                elif(j%2==0):
					# buying the stocks or no change
                   states[j]=max(states[j],states[j-1]-prices[i])
                else:
				   #selling the stocks or no change
                   states[j]=max(states[j],states[j-1]+prices[i])


        return states[2*k-1]