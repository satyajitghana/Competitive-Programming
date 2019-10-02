#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, coin, x, y;
    cin >> n >> coin;
    if(n==1)
        cout << "3 1" <<endl<< flush;
    else if(n <= 1000)
    {
        for(int a = 1; a <= n; a++)
        {
            cout << "1 " << a << endl << flush;
            int resp;
            cin >> resp;
            if(resp)
            {
                cout << "3 " << a << endl << flush;
                break;
            }
            else continue;
        }
    }
    else
    {
        int cres = 1000;
        int left = 1, right = n, mid = left + ((1 + sqrt(1+(8*(right-left))))/2) ;
        while(right - left +1 >= cres)
        {
            cout << "1 " << mid << endl << flush;
            int resp;
            cin >> resp;
            if(resp)
            {
                right = mid;
                mid = left + ((1 + sqrt(1+(8*(right-left))))/2) ;
                cout << "2" << endl << flush;
                cres -= (coin+1);
            }
            else
            {
                left = mid+1;
                mid = left + ((1 + sqrt(1+(8*(right-left))))/2) ;
                cres--;
            }
            //cout << cres << endl;
        }
        for(int a = left; a <= right; a++)
        {
            cout << "1 " << a << endl << flush;
            int resp;
            cin >> resp;
            if(resp)
            {
                cout << "3 " << a << endl << flush;
                break;
            }
            else continue;
        }
    }
}
