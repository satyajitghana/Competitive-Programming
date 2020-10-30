"""
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example:

Given '12:01:00PM'
Return '12:01:00'.

Given '12:01:00PM'
Return '00:01:00'.

"""

#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #
    # Write your code here.
    #
    stri = ""
    isAm = s[-2:]
    rest = s[:-2]
    nums = rest.split(':');
    if isAm == 'PM' and int(nums[0]) < 12:
        nums[0]=str(int(nums[0])+12)
    elif isAm == 'AM' :
        if nums[0] == '12' :
            nums[0] = '00'
    c = ":"        
    nums[0]=nums[0]+c
    nums[1]=nums[1]+c  
    
    return(stri.join(nums))        

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
