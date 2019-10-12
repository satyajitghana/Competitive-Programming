def check(d,x):
    count=0
    for i in range(0,d):
        if x[i] == 'P':
            count=count+1
    return count;
        

def fun(d,x):
    proxies=0
    calCount=check(d,x)
    total = (calCount/d)*100
    if total >= 75:
        return 0
    else:
        for i in range(2,d-2):
            if x[i] == 'A':
                if (x[i-1] == 'P' or x[i-2] == 'P') and (x[i+1] == 'P' or x[i+2] =='P' ):
                    calCount=calCount+1
                    total = (calCount/d)*100
                    proxies=proxies+1
                    if total >= 75:
                        break
    if total>=75:
        return proxies
    else:
        return -1

t=int(input())
if 1<=t and t<=200:
    while t>0:
        d = int(input())
        if 1<=d and d<=1000:
            x = list(map(str,input()))
            print(fun(d,x))
        t=t-1