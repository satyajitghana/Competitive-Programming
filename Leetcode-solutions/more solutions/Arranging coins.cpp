/* 
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.

Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/

class Solution {
public:
    int arrangeCoins(int n) {
        long row_num=0;
        long coins_used=0;
        //long coins_used_per_row=0;
        do
        {
            
            row_num++;
            //coins_used_per_row=row_num;
            coins_used=coins_used+row_num;
            if(coins_used>n)
                return row_num-1;
            
        }while(coins_used<n);
        return row_num;
    }
};