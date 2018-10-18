#include <bits/stdc++.h>

using namespace std;

string ans(const unordered_set<string> &se, const vector<vector<bool>> &chars, string word) {
    if (word.size() == chars.size()) {
        if (se.find(word) == se.end()) {
            return word;
        } 
        return "";
    }
    for (int i = 0; i < 26; ++i) {
        if (chars[word.size()][i]) {
            string symb = "A";
            symb[0] += i;
            string temp = ans(se, chars, word + symb);
            if (temp != "") {
                return temp;
            }
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int n, l;
        cin >> n >> l;
        vector<vector<bool>> chars(l, vector<bool>(26));
        unordered_set<string> se;
        while (n--) {
            string s;
            cin >> s;
            se.insert(s);
            for (int i = 0; i < s.size(); ++i) {
                chars[i][s[i] - 'A'] = true;
            }
        }
        string temp = "";
        temp = ans(se, chars, temp);
        cout << "Case #" << test << ": ";
        if (temp != "") {
            cout << temp << endl;
        } else {
            cout << "-\n";
        }
    }
    return 0;
}