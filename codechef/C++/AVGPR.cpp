#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        long int matr[2001];
        for(int a = 0; a < 2001; a++)
            matr[a] = 0;
        long long int total = 0;
        for(int a = 0; a < n; a++)
        {
            int t;
            cin >> t;
            matr[t+1000]++;
        }
//        for(int a = 0; a < n-1; a++)
//        {
//            for(int b = a + 1; b < n; b++)
//            {
//                int t1 = aj[a];
//                int t2 = aj[b];
//                if(t1==t2)
//                {
//                    int tp = matr[t1+1000];
//                    total++;
//                }
//                else
//                {
//                    if(((t1+t2)%2)==0)
//                    {
//                        int mean = (t1+t2)/2;
//                        int convm = mean + 1000;
//                        if(matr[convm])
//                        {
//                            total++;
//                        }
//                        else continue;
//                    }
//                    else continue;
//                }
//            }
//        }
        for(int a = 0; a < 2001; a++)
            for(int b = a; b < 2001; b++)
            {
                if(b==a)
                {
                    long long int t = matr[b];
                    total += (t * (t-1) / 2);
                }
                else
                {
                    if(((a+b)%2)==0)
                    {
                        int t = (a+b)/2;
                        if(matr[t]>0)
                        {
                            total += (matr[a] * matr[b]);
                            //cout << a << " " << b << " " << (matr[a]*matr[b]) << endl;
                        }
                        else continue;
                    }
                    else continue;
                }
            }
        cout << total << endl;
    }
}
