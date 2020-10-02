// this was fun!
class Solution {
public:
    //Solution()
    //{
     //   ios_base::sync_with_stdio(0); 
      //  cin.tie(0);
    //}
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        if(num==0)
            return result;
        int i=1;
        while(i<=num)
        {
            int n=i;
            int count=0;
            //if(i==1)
            //{
            //   count=1;
            //    result.push_back(count);
            //}
            while(n!=0)
            {
                count=count+n%2;
                n=n/2;
            }
            result.push_back(count);
            i++;
        }
        return result;
    }
};
