/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k > 30000)  return false;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();

         map<int, int> m;
         for(int i=0;i<n;i++)
         {
             if(m.find(nums[i])!=m.end())
             {
                 if(abs(m[nums[i]]-i)<=k)
                     return true;
                 else
                     m[nums[i]]=i;
             }
             else
                 m[nums[i]]=i;
         }
        return false;
    }
};