#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

using ll = long long;

int get_root(const vector<vector<int>> &edges) {
    queue<int> q;
    stack<int> s;
    vector<int> l(edges.size());
    vector<int> r(edges.size());
    vector<int> d(edges.size());
    vector<int> mark(edges.size(), 0);
    q.push(0);
    mark[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        s.push(u);
        for (int i : edges[u]) {
            if (mark[i] == 0) {
                mark[i] = 1;
                q.push(i);
            }
        }
    }
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        mark[u] = 2;
        for (int i : edges[u]) {
            if (mark[i] == 2) {
                if (l[i] + 1 > l[u]) {
                    r[u] = l[u];
                    l[u] = l[i] + 1;
                } else if (l[i] + 1 > r[u]) {
                    r[u] = l[i] + 1;
                }
            }
        }
    }
    q.push(0);
    mark[0] = 3;
    int best = r[0] + l[0];
    int root = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : edges[u]) {
            if (mark[i] != 3) {
                mark[i] = 3;
                d[i] = d[u] + 1;
                if (l[i] + 1 == l[u]) {
                    d[i] = max(d[i], r[u] + 1);
                } else {
                    d[i] = max(d[i], l[u] + 1);
                }
                if (best <= l[i] + max(r[i], d[i]) && edges[i].size() > 1) {
                    best = l[i] + max(r[i], d[i]);
                    root = i;
                }
                q.push(i);
            }
        }
    }
    return root;
}

struct node{
    vector<node*> sons;
    int height;
    int i;
};

void erase(node* r, set<pair<int, node*>> &se) {
    while (r != nullptr) {
        node* tt = nullptr;
        for (node* i : r->sons) {
            if (i->height + 1 != r->height || tt != nullptr) {
                se.insert(mp(i->height, i));
            } else {
                tt = i;
            }
        }
        delete r;
        r = tt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<vector<int>> edges(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edges[--a].push_back(--b);
        edges[b].push_back(a);
    }
    if (n == 2) {
        cout << "1 2" << endl;
        return 0;
    }
    int root = get_root(edges);
    node* r = new node();
    r->i = root;
    queue<node*> q;
    stack<node*> s;
    vector<bool> mark(n);
    mark[root] = true;
    q.push(r);
    while (!q.empty()) {
        node* u = q.front();
        q.pop();
        s.push(u);
        for (int i : edges[u->i]) {
            if (!mark[i]) {
                node* temp = new node();
                temp->i = i;
                u->sons.push_back(temp);
                q.push(temp);
                mark[i] = true;
            }
        }
    } 
    while (!s.empty()) {
        node* u = s.top();
        s.pop();
        u->height = 1;
        for (node* i : u->sons) {   
            u->height = max(u->height, i->height + 1);
        }
    }
    set<pair<int, node*>> se;
    node* ll = r->sons[0];
    node* rr = r->sons[1];
    int iii = 1;
    int lll = 0;
    if (ll->height < rr->height) {
        ll = r->sons[1];
        rr = r->sons[0];
        iii = 0;
        lll = 1;
    }
    for (int i = 2; i < r->sons.size(); ++i) {
        node* temp = r->sons[i];
        if (temp->height > ll->height) {
            rr = ll;
            iii = lll;
            ll = temp;
            lll = i;
        } else if (temp->height > rr->height) {
            rr = temp;
            iii = i;
        }
    }
    int k = rr->height;
    erase(rr, se);
    r->sons.erase(r->sons.begin() + iii);
    se.insert(mp(r->height, r));
    cout << 1;
    for (int i = 1; i < n; ++i) {
        if (se.empty()) {
            cout << " " << n;
        } else {
            auto temp = --se.end();
            k += temp->first; 
            r = temp->second;
            se.erase(temp);
            erase(r, se);
            cout << " " << k;
        }
    }
    cout << endl;
    return 0;
}
