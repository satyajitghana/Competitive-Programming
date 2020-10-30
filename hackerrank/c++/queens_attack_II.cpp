#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> v) {
    int sq=0;
    int west = c_q - 1;
    int east = n - c_q;
    int south = r_q -1;
    int north = n - r_q;
    int nw = north > west? west: north;
    int ne = north > east? east: north;
    int sw = south > west? west: south;
    int se = south > east? east: south;
    sq = west+east+south+north+nw+ne+sw+se;
    
    int wo=0; 
    int eo=0;
    int no=0;
    int so=0;
    int neo=0;
    int nwo=0; 
    int seo=0;
    int swo=0, x=0;
    for(int i=0;i<k;i++){
        if(r_q==v[i][0]){
        int y =  v[i][1] > c_q ? n -v[i][1]+ 1: v[i][1];
         if(wo<y && v[i][1] < c_q ) wo = y;
         if(eo<y && v[i][1] > c_q) eo = y;
        }
        if(c_q==v[i][1]){
            x = v[i][0] > r_q ? n - v[i][0] + 1: v[i][0] ;
            if(so<x && v[i][0] < r_q ) so = x;
            if(no<x && v[i][0] > r_q) no = x;
        }
        if(abs(r_q - v[i][0]) == abs(c_q - v[i][1]) ){
            if(r_q > v[i][0] && c_q > v[i][1]){
                //sw
                x = v[i][0]> v[i][1]? v[i][1]: v[i][0];
                if(swo<x) swo = x;
            }
            if(r_q < v[i][0] && c_q > v[i][1]){
                //nw
                x = n-v[i][0]+1> v[i][1]? v[i][1]: n- v[i][0]+1;
                if(nwo<x) nwo = x;
            }
            if(r_q < v[i][0] && c_q < v[i][1]){
                //ne
                x = n-v[i][0]+1>n- v[i][1]+1? n- v[i][1]+1: n- v[i][0]+1;
                if(neo<x) neo = x;
            }
            if(r_q > v[i][0] && c_q < v[i][1]){
                //se
                x = v[i][0]>n- v[i][1]+1? n- v[i][1]+1: v[i][0];
                if(seo<x) seo = x;

            }
        }
    }
    return sq - wo - eo - no - so - seo - neo - swo - nwo;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
