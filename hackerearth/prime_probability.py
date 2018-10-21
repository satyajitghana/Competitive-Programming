n=int(input())
x=n+1
arr=[1]*x

for i in range(2,n+2):
	
	for j in range(2*i,n+1,i):
		if(arr[j]==1):
			arr[j]=0
s=sum(arr[2:n+1])
a=n-1
b=s


while(b!=0):
	a,b=b,a%b

print(str(s//a)+'/'+str(n//a))
