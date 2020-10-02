class Solution {
public:
    string removeKdigits(string num, int k) {
        //int count=0;
       // int i=0;
       // int x=num.size();
        if(k==num.size())
            return "0";
       // for (int i=0;i<num.size();i++)
        if(k==0)
            return num;
 /*       while(i<num.length()-1)
        {
            if(num[i]>num[i+1])
            {
                num.erase(num.begin()+i);
                count++;
                //i--;
                if(i==num.length()-1)
                    i--;
               // cout<<num<<endl;
           }
            else
                i++;
            if(count==k)
            {
                while(num[0]=='0')
                {
                    if(num.size()==1)
                        break;
                    //cout<<num<<endl;
                    num.erase(num.begin());
                    //cout<<num<<endl;
                }
                return num;
            }
            
        }
        int fcount=k-count;
        while(fcount>0)
        {
            //int j= num.end();
            cout<<num<<endl;
            num.erase(num.length()-1,1);
            //cout<<num<<endl;
            fcount--;
        }
        return num; */
        for (int j=0;j<k;j++)
        {
            int i=0;
            while(i<num.length()-1 && num[i]<=num[i+1])
            {
                i++;
            }
            num.erase(num.begin()+i);
            //cout<<num<<endl;
        }
        while(num.size()>1 && num[0]=='0')
        {
            num.erase(num.begin());
        }
        return num;
        
    }
};
