T=int(input())
for t in range(0,T):
	front=input()
	back=input()
	b=0
	o=0
	b2=0
	for i in range(0,3):
		if front[i]=='b' or front[i] == 'B' or back[i]=='B' or back[i]=='b':
			b=1
			for j in range(0,3):
				if i==j:
					continue
				if front[j]=='o' or front[j]=='O' or back[j]=='o' or back[j]=='O':
					o=1
					for k in range(0,3):
						if j==k or i==k:
							continue
						if front[k]=='b' or front[k]=='B' or back[k]=='B' or back[k]=='b':
							b2=1	
	if b==1 and o==1 and b2==1:
		print("yes")
	else:
		print("no")
