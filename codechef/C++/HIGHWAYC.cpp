#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    long long int t;
    cin >> t;
    for(int a = 0; a  < t; a++)
    {
        int n;
        double s, y;
        cin >> n >> s >> y;
        double v[n], d[n], p[n], c[n];
        for(int b = 0; b < n; b++)
            cin >> v[b];
        for(int b = 0; b < n; b++)
        {
            cin >> d[b];
            if(d[b]==0)
                d[b]= -1;
        }
        for(int b = 0; b < n; b++)
            cin >> p[b];
        for(int b = 0; b < n; b++)
            cin >> c[b];
        double time = 0;
        for(int b = 0; b < n; b++)
        {
            p[b] = p[b] + d[b]*(time*v[b]);
            if(p[b]*d[b] > 0)
            {
                if(abs(p[b])-c[b]<0)
                {
                    time += ((c[b]-abs(p[b]))/v[b]);
                    time += y/s;
                    time += 0.000001/v[b];
                }
                else
                {
                    time += y/s;
                }
            }
            else if(p[b]==0)
            {
                time+= (c[b]/v[b]);
                time += 0.000001/v[b];
                time+= y/s;
                //cout << "in here";
            }
            else if(p[b]*d[b]<0)
            {
                //float absp = abs(p[b]);
                //cout << (y/s)-(abs(p[b])/v[b]) << endl;
                if((abs(p[b])/v[b]) - y/s > 0.000001/v[b])
                {
                    time+= y/s;
                }
                else
                {
                    time += ((c[b] + abs(p[b]) )/ v[b]);
                    time += 0.000001/v[b];
                    time += y/s;
                }
            }
        }
        printf("%.6lf\n",  time);
    }
}

