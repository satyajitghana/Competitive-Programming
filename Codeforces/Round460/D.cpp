#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int digits(int num) {
int ans = 0;
while(num > 0) {
ans += num % 10;
num /= 10;
}
return ans;
}

int main() {
int n, m;
string s;
cin >> n >> m >> s;
vector<vector<int>> out(n);
vector<int> in(n);
for (int i = 0; i < m; ++i) {
int a, b;
cin >> a >> b;
out[--a].push_back(--b);
++in[b];
}
queue<int> q;
stack<int> st;
for (int i = 0; i < n; ++i) {
if (in[i] == 0) {
q.push(i);
}
}
int a = q.front();
q.pop();
st.push(a);
for (int i : out[a]) {
--in[i];
if (in[i] == 0) {
q.push(i);
}
}
}
if (st.size() != n) {
cout << -1 << endl;
return 0;
}
vector<vector<int>> v(n, vector<int> (26));
int a = st.top();
st.pop();
int u = s[a] - 'a';
v[a][u] = 1;
for (int i : out[a]) {
for (int j = 0; j < 26; ++j) {
if (j != u) {
v[a][j] = max(v[a][j], v[i][j]);
} else {
v[a][j] = max(v[a][j], v[i][j] + 1);
}
}
}
}
int ans = 0;
for (int i = 0; i < n; ++i) {
for (int j = 0; j < 26; ++j) {
ans = max(ans, v[i][j]);
}
}
cout << ans << endl;
return 0;
}
