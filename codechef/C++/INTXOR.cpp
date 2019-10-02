#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t)
    {
        t--;
        int n;
        cin >> n;
        long long int aj[n+1];
        int rem = n;
        for(int a = 1; rem>0;)
        {
            if(rem==11)
            {
                long long int abc, bcd, cde, def, efg, fgh, ghi, hij, ijk, jka, kab;
                cout << "1 " << a << " " << a+1 << " " << a+2 << endl << flush;
                cin >> abc;
                cout << "1 " << a+1 << " " << a+2 << " " << a+3 << endl << flush;
                cin >> bcd;
                cout << "1 " << a+2 << " " << a+3 << " " << a+4 << endl << flush;
                cin >> cde;
                cout << "1 " << a+3 << " " << a+4 << " " << a+5 << endl << flush;
                cin >> def;
                cout << "1 " << a+4 << " " << a+5 << " " << a+6 << endl << flush;
                cin >> efg;
                cout << "1 " << a+5 << " " << a+6 << " " << a+7 << endl << flush;
                cin >> fgh;
                cout << "1 " << a+6 << " " << a+7 << " " << a+8 << endl << flush;
                cin >> ghi;
                cout << "1 " << a+7 << " " << a+8 << " " << a+9 << endl << flush;
                cin >> hij;
                cout << "1 " << a+8 << " " << a+9 << " " << a+10 << endl << flush;
                cin >> ijk;
                cout << "1 " << a+9 << " " << a+10 << " " << a << endl << flush;
                cin >> jka;
                cout << "1 " << a+10 << " " << a << " " << a+1 << endl << flush;
                cin >> kab;

                aj[a] = bcd ^ efg ^ hij ^ kab ^ cde ^ fgh ^ ijk;
                aj[a+1] = cde ^ fgh ^ ijk ^ abc ^ def ^ ghi ^ jka;
                aj[a+2] = def ^ ghi ^ jka ^ bcd ^ efg ^ hij ^ kab;
                aj[a+3] = efg ^ hij ^ kab ^ cde ^ fgh ^ ijk ^ abc;
                aj[a+4] = fgh ^ ijk ^ abc ^ def ^ ghi ^ jka ^ bcd;
                aj[a+5] = ghi ^ jka ^ bcd ^ efg ^ hij ^ kab ^ cde;
                aj[a+6] = hij ^ kab ^ cde ^ fgh ^ ijk ^ abc ^ def;
                aj[a+7] = ijk ^ abc ^ def ^ ghi ^ jka ^ bcd ^ efg;
                aj[a+8] = jka ^ bcd ^ efg ^ hij ^ kab ^ cde ^ fgh;
                aj[a+9] = kab ^ cde ^ fgh ^ ijk ^ abc ^ def ^ ghi;
                aj[a+10] =  abc ^ def ^ ghi ^ jka ^ bcd ^ efg ^ hij;

                rem-=11;
                a+=11;

            }
            else if(rem%4==0)
            {
                long long int abc, bcd, cda, dab;
                cout << "1 " << a << " " << a+1 << " " << a+2 << endl << flush;
                cin >> abc;
                cout << "1 " << a+1 << " " << a+2 << " " << a+3 << endl << flush;
                cin >> bcd;
                cout << "1 " << a+2 << " " << a+3 << " " << a << endl << flush;
                cin >> cda;
                cout << "1 " << a+3 << " " << a << " " << a+1 << endl << flush;
                cin >> dab;

                aj[a] = abc ^ cda ^ dab;
                aj[a+1] = abc ^ bcd ^ dab;
                aj[a+2] = abc ^ bcd ^ cda;
                aj[a+3] = bcd ^ cda ^ dab;

                rem-=4;
                a+=4;
            }
            else
            {
                long long int abc, bcd, cde, dea, eab;
                cout << "1 " << a << " " << a+1 << " " << a+2 << endl << flush;
                cin >> abc;
                cout << "1 " << a+1 << " " << a+2 << " " << a+3 << endl << flush;
                cin >> bcd;
                cout << "1 " << a+2 << " " << a+3 << " " << a+4 << endl << flush;
                cin >> cde;
                cout << "1 " << a+3 << " " << a+4 << " " << a << endl << flush;
                cin >> dea;
                cout << "1 " << a+4 << " " << a << " " << a+1 << endl << flush;
                cin >> eab;

                aj[a] = cde ^ eab ^ bcd;
                aj[a+1] = dea ^ abc ^ cde;
                aj[a+2] = eab ^ bcd ^ dea;
                aj[a+3] = abc ^ cde ^ eab;
                aj[a+4] = bcd ^ dea ^ abc;

                rem-=5;
                a+=5;
            }
        }

        cout << "2 ";
        for(int a = 1; a <= n; a++)
            cout << aj[a] << " ";
        cout << endl << flush;
        int resp;
        cin >> resp;
        if(resp == 1)
            continue;
        else break;
    }
}
