#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, cut;
    cin >> n >> cut;
    for(int a =0; a < n; a++)
    {
        int r;
        cin >> r;
        if(r>=cut)
            cout << "Good boi" << endl;
        else cout << "Bad boi" << endl;
    }
}
