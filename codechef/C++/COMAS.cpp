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
        int th, fo;
        cout << "? 1 2 3 4 5" << endl << flush;
        cin >> th >> fo;
        int send[] = { 1 , 2 , 3 , 4 , 5};
        for(int a = 0; a+6 < n;)
        {
            for(int b = 0; b < 5; b++)
            {
                if(send[b]==th)
                    send[b] = ((a+5)%n)+1;
                if(send[b]==fo)
                    send[b] = ((a+6)%n)+1;
            }
            cout << "? " << send[0] << " " << send[1] << " " << send[2] << " " << send[3] << " " << send[4]<< endl << flush;
            cin >> th >> fo;
            a+=2;
        }
        if(!(n%2))
        {
            for(int b = 0; b < 5; b++)
            {
                if(send[b]==fo)
                    send[b] = n;
            }
            cout << "? " << send[0] << " " << send[1] << " " << send[2] << " " << send[3] << " " << send[4]<< endl << flush;
            cin >> th >> fo;
        }
        int gem[3], i=0;
        for(int a = 0; a < 5; a++)
        {
            if(send[a]==th || send[a]==fo)
                continue;
            else
            {
                gem[i] = send[a];
                i++;
            }
        }
        int samp[3];
        i=0;
        for(int a = 1; a<= n && i<3;a++)
        {
            if(a == gem[0] || a==gem[1] || a==gem[2])
                continue;
            else
            {
                samp[i] = a;
                i++;
            }
        }
        cout << "? " << gem[0] << " " << gem[1] << " " << samp[2] << " " << samp[1] << " " << samp[0]<< endl << flush;
        int samp1[2], samp2[2];
        cin >> samp1[0] >> samp1[1];
        cout << "? " << gem[1] << " " << gem[2] << " " << samp[2] << " " << samp[1] << " " << samp[0]<< endl << flush;
        cin >> samp2[0] >>  samp2[1];
        if(samp1[0]==samp2[0] && samp1[1]==samp2[1])
        {
            cout << "! " << gem[1] << endl << flush;
        }
        else
        {
            int samp3[2];
            cout << "? " << gem[0] << " " << gem[2] << " " << samp[2] << " " << samp[1] << " " << samp[0]<< endl << flush;
            cin >> samp3[0] >>  samp3[1];
            if(samp1[0]==samp3[0] && samp1[1]==samp3[1])
            {
                cout << "! " << gem[0] << endl << flush;
            }
            else cout << "! " << gem[2] << endl << flush;
        }
    }B
}
