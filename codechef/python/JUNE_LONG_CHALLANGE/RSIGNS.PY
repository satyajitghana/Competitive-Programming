import math

MOD = 1000000007
def fast_power(base, power):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % MOD
        power = power // 2
        base = (base * base) % MOD

    return result

t = int(input())
dt=[]
while t>0:
    if 1<=t and t<=10**5:
        k=int(input())
        print(((fast_power(2,k-1))*10)%((10**9)+7))
    t=t-1