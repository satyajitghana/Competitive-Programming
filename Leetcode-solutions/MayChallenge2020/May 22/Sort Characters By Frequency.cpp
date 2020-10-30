  
class Solution {
public:
    string frequencySort(string s) {
        if(s.length()==0)
            return "";
        if(s.length()==1)
            return s;
        sort(s.begin(),s.end());
        vector<pair<int,char>>v;
      //vector<char>c;
        int count=1;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
                count++;
            else
            {
                v.push_back(make_pair(count,s[i]));
                //push_back(s[i]);
                count=1;
            }
        }
        v.push_back(make_pair(count,s[s.length()-1]));
        // v.push_back(count);
        // c.push_back(s[s.length()-1]);
        sort(v.begin(),v.end());
      //sort(c.egin(),c.end());
        string ans;
        for(int i=v.size()-1;i>=0;i--)
        {
           // ans.push_back(v[i].first*v[i].second);
           ans=ans+ string(v[i].first, v[i].second);
        }
        return ans;
    }
};
