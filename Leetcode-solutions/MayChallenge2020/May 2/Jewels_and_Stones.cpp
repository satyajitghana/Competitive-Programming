class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::string::iterator i; 
        std::string::iterator j;
        int count =0;
        for(i=J.begin(); i!=J.end(); i++)
        {
            for(j=S.begin(); j!=S.end(); j++)
            {
                if (*j==*i)
                {
                    count ++;
                }
            }
        }
      return count;  
    }
};
