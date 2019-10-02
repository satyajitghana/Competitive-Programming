#include<iostream>
#include<cmath>

using namespace std;

const long long int mod = 1000000007;
const long long int num1 = 999999937;

long long int power(long long int x, unsigned long long int y, long long int p)
{
    long long int res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for(int a = 0; a < t; a++)
    {
        long long int n, w;
        cin >> n >> w;
        if(w>9 || w < -9)
            cout << "0\n";
        else
        {
            long long int tot = 1;
            tot = power(10, n-2, mod);
            if(w==0)
                tot = (tot * 9) % mod;
            else if(w>0)
                tot = ((tot * (9- w)) % mod);
            else if(w<0)
                tot = ((tot * (10 + w)) % mod);
            cout << tot << endl;
        }
    }
}
