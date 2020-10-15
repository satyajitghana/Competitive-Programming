class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.size() == 0) // no words in list
            return "";
        
        else if (strs.size() == 1) // one word in list - prefix of itself
            return strs[0];
        
        string prefix = strs[0]; 
        
        for (int i=1;i<strs.size();i++) // find the shortest word - to start with
        {
            if (strs[i].length() == 0) // empty string
                return "";
            
            if (strs[i].length() < prefix.length())
                prefix = strs[i];
        }
        
        for (int i=0; i<strs.size();i++) // for each word, compare with prefix
        {
            for (int j=0; j<strs[i].length(); j++)
            {
                if (prefix[j] != strs[i][j]) // if reached a letter that is not the same, shorten common prefix
                {
                    prefix = prefix.substr(0, j);
                    break;
                }
            }
        }
        return prefix; 
    }
};
