class Solution {
public:
    int firstUniqChar(string s) {
        int i; 
        int j=0;
        for(i=0;i<s.length();i++)
        {
            j=0;
            while(j<=s.length())
            {
                if(s[i]==s[j]&& i!=j)
                    break;
                
               else if(s[i]!=s[j] &&j==s.length())
                    return i;
                
                else
                    j++;
                    
            }

        }
        return -1;
    }
};

//I know some unnecessary looping is taking place, but couldn't figure out how to reduce it! 
