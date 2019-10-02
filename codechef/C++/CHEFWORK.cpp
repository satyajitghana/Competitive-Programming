#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int coin[n], type[n], mina = 100001, mint = 100001, minat = 100001;
    for(int a = 0; a < n; a++)
        cin >> coin[a];
    for(int a = 0; a < n; a++)
    {
        cin >> type[a];
        if(type[a]==1)
            mint = min(mint, coin[a]);
        else if(type[a]==2)
            mina = min(mina, coin[a]);
        else if(type[a]==3)
            minat = min(minat, coin[a]);
    }
    cout << min((mint+mina), minat) << endl;
}
