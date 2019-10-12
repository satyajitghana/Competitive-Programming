def call(y):
    if y%10 == 0:
        return 0
    elif y<10:
        return 10-y
    elif y>=10 and y<100 :
        ystr = str(y)
        term = (int(ystr[-2])+1)*10 - y
        return term
    elif y>=100 and y<1000:
        ystr = str(y)
        term = (int(ystr[-3])*100) +(int(ystr[-2])+1)*10 - y
        return term
        
t = int(input())
if 1<=t and t<=10**5:
    while(t>0):
        n = int(input())
        s = str(n)
        y = 0
        if 1<=n and n<=10**18:
            for i in range(0,len(s)):
                y = y + int(s[i])
            print(s + str(call(y)))        
        t=t-1