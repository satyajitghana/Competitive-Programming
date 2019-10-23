lst=input().split()
a=int(lst[0])
b=float(lst[1])
if a%5==0 and (a+0.5)<=b:
   print(b-a-0.5)
elif a%5!=0 or (a+0.5)>b:
   print(b)
