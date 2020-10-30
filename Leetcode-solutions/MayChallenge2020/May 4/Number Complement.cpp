//solution credit to Tejas Shah!!

class Solution {
public:
    int findComplement(int num) {
        
        
        stack<int>q;
        while(1)
        {
            int temp=num%2;
            q.push(temp);
            num=num/2;
            if(num==0)
                break;
            
        }
        vector<int>v;
        while(!q.empty())
        {
            // cout<<q.top();
            // q.pop();
            int x;
            if(q.top()==1)
                 x=0;
            else
                x=1;
            //cout<<x;
            v.push_back(x);
            q.pop();
                
        }
        int sum=0;
        int j=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            sum=sum+(pow(2,i)*v[j]);
           // cout<<sum;
            j++;
        }
        return sum;
        
    }
};

//I expected something star wars themed today...you know, May the fourth!
