class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int count=0,maxcount=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==0)
        //         count++;
        //     else
        //         break;
        // }
        // maxcount=nums.size()-count;
        // int temp=max(count,maxcount)-min(count,maxcount);
        // return nums.size()-temp;
        // return maxcount;
        //vector<int>v;
        int sum=0,maxlength=0;
        map<int,int>m;
        // if(nums[0]==0)
        // {
        //     m[0]==-1;
        // }
        // else
        // {
        //     m[0]==1;
        // }
      //  m[0]=0;
     //   v.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                sum--;
            else
                sum++;
             if (sum == 0) 
                maxlength = i + 1;
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
               // cout<<sum<<i<<"\n";
            }
            else
            {
                int length=i-m[sum];
             //  cout<<i<<"\t"<<sum<<"\t"<<length<<"\n";
                if(length>maxlength)
                maxlength=length;
            }
            
        }
       
        return maxlength;
    }
};
