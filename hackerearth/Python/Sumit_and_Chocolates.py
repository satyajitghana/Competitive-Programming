n=int(input())
c=list(map(int,input().split()))
su=0

s=[]
for x in c:
	su+=x
	s.append(su)

	
for _ in range(int(input())):
	x=int(input())
	l=0
	r=n-1
	f=0
	
	while(f==0 and l<=r):
		m=(l+r)//2
		s1=s[m]
		
		if(x>s1-c[m] and x<=s1):
			f=1
		elif(x>s1):
			l=m+1
		else:
			r=m-1
	print(m+1)
