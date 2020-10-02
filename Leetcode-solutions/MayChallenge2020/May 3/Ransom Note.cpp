class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::string::iterator i; 
        std::string::iterator j;
        int count = 0;
        if(ransomNote.length()==0)
            return true;
        for(i=ransomNote.begin();i!=ransomNote.end();i++)
        {
            for(j=magazine.begin();j!=magazine.end();j++)
            {
                if(*i==*j)
                {
                    count++;
                    *j=' ';
                    if (count==ransomNote.length())
                        return true;
                    break;
                }
            }
        }
        return false;
    }
};
