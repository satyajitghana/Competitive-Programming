/*

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3

Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

 
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(),nums.end());
        if(nums.size()<3)
            return nums[0];
        for(int i=0;i<nums.size()-3;i=i+3)
        {
            int j=i+2;
            if(nums[i]!=nums[j])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};