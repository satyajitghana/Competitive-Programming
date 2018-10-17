#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

const int MAX = 1000000;

struct triple {
    int64_t l = 0;
    int64_t c = 0;
    int64_t r = 0;
    int64_t d = 0;
};

int64_t distance(const set<int64_t> &left, const set<int64_t> &right, int64_t k) {
    if (!left.empty()) {
        k += *(--left.end());
    }
    if (!right.empty()) {
        k += *(--right.end());
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[--a].emplace_back(make_pair(--b, c));
        edges[b].emplace_back(make_pair(a, c));
    }
    vector<int64_t> mark(n, -1);
    vector<int> ancestor(n, -2);
    stack<int> s;
    s.push(0);
    mark[0] = 0;
    ancestor[0] = -1;
    vector<int> cycle;
    while (!s.empty()) {
        int i = s.top();
        s.pop();
        if (mark[i] == edges[i].size()) {
            mark[i] = MAX;
        } else if (mark[edges[i][mark[i]].first] == -1) {
            s.push(i);
            s.push(edges[i][mark[i]].first);
            mark[edges[i][mark[i]].first] = 0;
            ancestor[edges[i][mark[i]].first] = i;
            ++mark[i];
        } else if (mark[edges[i][mark[i]].first] == MAX) {
            int temp = edges[i][mark[i]].first;
            while (mark[temp] == MAX) {
                cycle.push_back(temp);
                temp = ancestor[temp];
            }
            cycle.push_back(temp);
            stack<int> s_temp;
            s_temp.push(i);
            while (mark[s.top()] != temp) {
                s_temp.push(s.top());
                s.pop();
            }
            while (!s_temp.empty()) {
                cycle.push_back(s_temp.top());
                s_temp.pop();
            }
            break;
        } else {
            int temp = edges[i][mark[i]].first;
            if (edges[temp][mark[temp] - 1].first != i) {
                cycle.push_back(i);
                while (s.top() != temp) {
                    cycle.push_back(s.top());
                    s.pop();
                }
                cycle.push_back(s.top());
                break;
            } else {
                ++mark[i];
                s.push(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ancestor[i] = -2;
        mark[i] = 0;
    }
    for (int i : cycle) {
        ancestor[i] = -1;
    }
    int64_t temp_ans = 0;
    vector<int64_t> max_len(cycle.size());
    vector<int64_t> dist(cycle.size());
    for (int i = 0; i < cycle.size(); ++i) {
        for (int j = 0; j < edges[cycle[i]].size(); ++j) {
            if (edges[cycle[i]][j].first == cycle[(i + 1) % cycle.size()]) {
                dist[i] = edges[cycle[i]][j].second;
            }
        }
        queue<pair<int, int64_t>> q;
        q.push(make_pair(cycle[i], 0));
        stack<pair<int, int>> s;
        s.push(make_pair(cycle[i], 0));
        while (!q.empty()) {
            pair<int, int64_t> temp = q.front();
            q.pop();
            max_len[i] = max(max_len[i], temp.second);
            for (int j = 0; j < edges[temp.first].size(); ++j) {
                if (ancestor[edges[temp.first][j].first] == -2) {
                    q.push(make_pair(edges[temp.first][j].first,
                                     temp.second + edges[temp.first][j].second));
                    ancestor[edges[temp.first][j].first] = temp.first;
                    s.push(edges[temp.first][j]);
                }
            }
        }
        while (!s.empty()) {
            pair<int, int> temp = s.top();
            s.pop();
            if (ancestor[temp.first] != -1) {
                temp_ans = max(temp_ans, mark[ancestor[temp.first]] + mark[temp.first] + temp.second);
                mark[ancestor[temp.first]] = max(mark[ancestor[temp.first]], mark[temp.first] + temp.second);
            }
        }
    }

    int64_t tree = 1;
    while (tree < cycle.size()) {
        tree *= 2;
    }
    tree *= 2;

    vector<triple> w(tree * 2);
    for (int i = 0; i < cycle.size(); ++i) {
        w[tree + i].l = max_len[i];
        w[tree + i].c = max_len[i];
        w[tree + i].r = max_len[i] + dist[i];
        w[tree + i].d = dist[i];
        w[tree + cycle.size() + i].l = max_len[i];
        w[tree + cycle.size() + i].c = max_len[i];
        w[tree + cycle.size() + i].r = max_len[i] + dist[i];
        w[tree + cycle.size() + i].d = dist[i];
    }
    w[tree + 2 * cycle.size() - 1].r = 0;
    w[tree + 2 * cycle.size() - 1].d = 0;

    for (int i = tree - 1; i > 0; -- i) {
        w[i].l = max(w[2 * i].l, w[2 * i + 1].l + w[2 * i].d);
        w[i].c = max(w[2 * i].c, max(w[2 * i + 1].c, w[2 * i].r + w[2 * i + 1].l));
        w[i].r = max(w[2 * i + 1].r, w[2 * i].r + w[2 * i + 1].d);
        w[i].d = w[2 * i].d + w[2 * i + 1].d;
    }

    int64_t ans = INT64_MAX;
    for (int i = 0; i < cycle.size(); ++i) {
        int64_t temp = 0;
        int l = tree + i;
        int r = l + cycle.size();
        int64_t lr = 0;
        int64_t rl = -w[r - 1].d;
        while (l + 1 < r) {
            if (l % 2 != 0) {
                temp = max(temp, max(w[l].c, lr + w[l].l));
                lr = max(w[l].r, lr + w[l].d);
                ++l;
            }
            if (r % 2 != 0) {
                --r;
                temp = max(temp, max(w[r].c, rl + w[r].r));
                rl = max(w[r].l, rl + w[r].d);
            }
            if (l == r) {
                temp = max(temp, lr + rl);
            }
            l /= 2;
            r /= 2;
        }
        if (l + 1 == r) {
            temp = max(temp, max(w[l].c, max(lr + w[l].l, max(rl + w[l].r, lr + w[l].d + rl))));
        }
        ans = min(ans, temp);
    }

    cout << max(ans, temp_ans) << endl;
    return 0;
}
