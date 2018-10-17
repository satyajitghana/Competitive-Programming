//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Tree {
//public:
//    Tree(int size) {
//        while (p < size) {
//            p *= 2;
//        }
//        v = vector<pair<int, int>>(2 * p);
//    }
//
//    void add(int left, int right) {
//        add(left, right, 1, 0, p);
//    }
//
//    void insert(int pos, int value) {
//        pos += p;
//        v[pos].first = value;
//        while (pos > 1) {
//            pos /= 2;
//            v[pos].first = max(v[pos * 2].first + v[pos * 2].second, v[pos * 2 + 1].first);
//        }
//    }
//
//    int get_max() {
//        return v[1].first + v[1].second;
//    }
//
//private:
//    vector<pair<int, int>> v;
//    int p = 1;
//
//    void add(int left, int right, int i, int lo, int ro) {
//        if (left <= lo && ro <= right) {
//            if (i < p) {
//                ++v[i].second;
//            } else {
//                ++v[i].first;
//            }
//        } else {
//            v[2 * i].second += v[i].second;
//            v[2 * i + 1].second += v[i].second;
//            v[i].second = 0;
//            if (left < (lo + ro) / 2) {
//                add(left, right, i * 2, lo, (lo + ro) / 2);
//            }
//            if ((lo + ro) / 2 < right) {
//                add(left, right, i * 2 + 1, (lo + ro) / 2, ro);
//            }
//            v[i].first = max(v[2 * i].first + v[2 * i].second,
//                             v[2 * i + 1].first + v[2 * i + 1].second);
//        }
//    }
//};
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> ans(n);
//    vector<int> cookies(n);
//    vector<int> input(n);
//    for (int &i : input) {
//        cin >> i;
//        --i;
//    }
//    int m = 0;
//    for (int i = 0; i < n; ++i) {
//        if (!cookies[input[i]]) {
//            cookies[input[i]] = 1;
//            ++m;
//        }
//        ans[i] = m;
//    }
//    for (int i = 1; i < k; ++i) {
//        cookies.clear();
//        cookies.resize(n);
//        vector<int> temp(n);
//        Tree tree(n);
//        for (int j = 1; j < n; ++j) {
//            tree.insert(j - 1, ans[j - 1]);
//            tree.add(cookies[input[j]], j);
//            cookies[input[j]] = j;
//            temp[j] = tree.get_max();
//        }
//        ans = move(temp);
//    }
//    cout << ans[n - 1] << endl;
//    return 0;
//}

