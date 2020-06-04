class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1)
            return 1;
        for(int i=0;i<trust.size();i++)
        {
                int x=i;
           // cout<<i<<endl<<x<<endl;
                int count=0;            
            while(x<trust.size())
            {
                //int y=0;
                if(trust[x][1]==trust[i][1])
                {
                    count++;
                }
                x++;
               // cout<<x<<"   "<<count<<endl;
                if(count==N-1)
                {
                    int y= trust[i][1];
                    int x=0;
                    while(x<trust.size())
                    {
                        if(trust[x][0]==trust[i][1])
                            return -1;
                        x++;
                    }
                    return y;
                }
            }
        }
        return -1;
        
    }
};
