//My solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=0,count=1,count1=0;
        for (int i=1;i<nums.size();i++)
        {
            if(nums[maj]==nums[i])
                count++;
            else 
                count--;
            if(count==0)
            {
                maj=i;
                count=1;
            }
        }
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==nums[maj])
                count1++;
            if(count1>nums.size()/2)
                return(nums[maj]);
        }
     return -1;   
        
    }
};

//solution i found online
class Solution {
 public:
     int majorityElement(vector<int>& nums) {
         sort(nums.begin(), nums.end());
         return nums[nums.size()/2];
     }
 };
 
 //Holy cow! What a simple and elegant solution!!!
