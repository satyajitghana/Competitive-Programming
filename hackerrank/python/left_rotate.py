'''A left rotation operation on an array shifts each of the array's elements given units to the left.
Given an array and the number of left shifts to be performed, print the resulting array after rotation'''

def rotLeft(a, d):
    b = [i for i in a]
    leng = len(a)
    for i in range(leng):
        b[i] = a[(i+d)%leng]
    return b


nd = input().split() #enter the size of array and number of left rotations to perform eg: 5 4

n = int(nd[0])

d = int(nd[1])

a = list(map(int, input().rstrip().split()))  #enter an array of above given size 

result = rotLeft(a, d)
print(result)
