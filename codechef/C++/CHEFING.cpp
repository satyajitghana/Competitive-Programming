#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[150];
        memset(a, 0, sizeof(a));
        set<int> s1;
        int n;
        cin >> n;
        int get = n;
        while (n--)
        {
            string s;
            cin >> s;
            for (int i = 0; i < s.length(); i++)
            {
                s1.insert((int)s[i]);
            }
            for (auto it = s1.begin(); it != s1.end(); it++)
            { cout<<" *"<<*it << "* ";

                a[*it]++;
            }
            s1.clear();
        }
        int cnt = 0;
        for (int i = 97; i <= 140; i++)
        {

            if (a[i] == get)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}