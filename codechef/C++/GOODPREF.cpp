#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a = 0; a < t; a++)
    {
        string res;
        int n;
        cin >> res >> n;
        int aj[res.length()], sum = 0, maxpresum= 0, minpresum=10000, lim = 0;
        long long int tot = 0;
        for(int a = 0; a < res.length(); a++)
        {
            if(res[a]=='a')
            {
                aj[a] = 1;
                sum++;
            }
            else
            {
                aj[a] = -1;
                sum--;
            }
            maxpresum = max(maxpresum, sum);
            minpresum = min(minpresum, sum);
            if(sum>0)
                tot++;
        }
        int finsum = sum;
        int c = 1;
        if(finsum == 0)
        {
            tot = tot*n;
            c = 0;
        }
        //cout << tot << endl;
        if(c)
        {
            for(long long int a = 0; a < n-1; a++)
            {
                int tempsum = 0;
                for(int b = 0; b < res.length(); b++)
                {
                    tempsum+= aj[b];
                    if(tempsum > -1 * sum)
                        tot++;
                }
                sum += finsum;
                if(sum > -1*minpresum)
                {
                    tot += ((n-(a+2))*res.length());
                    break;
                }
                if(sum < -1*maxpresum)
                {
                    break;
                }
            }
        }
        else if(c == -1)
        {
            if(finsum ==0 )
                tot = tot*n;
            else if(finsum > 0)
            {

            }
            else if(finsum < 0)
            {

            }
        }
        cout << tot << endl;
    }
}
