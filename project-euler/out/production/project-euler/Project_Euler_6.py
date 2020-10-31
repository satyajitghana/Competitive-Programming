t=int(input())
for q in range(t):
    n=int(input())
    sum1=int((n*(n+1)*(2*n+1))/6)
    sum2=int((n*(n+1))/2)
    sum2=sum2**2
    print(abs(sum1-sum2))