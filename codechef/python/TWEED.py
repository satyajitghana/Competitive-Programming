T = input()
arr=[]
while T > 0 :
    N = input()
    S = raw_input()
    T-=1
    while N > 0 :
        arr.append(input())
        N-=1
    print arr
