#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

class MinStack {
public:
	MinStack() {}
	void push(int i) {
		s.push(i);
        if (m.size() != 0) {
            m.push(min(i, m.top()));
        } else {
            m.push(i);
        }
	}
	void pop() {
		s.pop();
		m.pop();
	}
	int get() {
		return s.top();
	}
	int mmin() {
		return m.top();
	}
	int size() {
		return s.size();
	}
private:
	stack<int> s;
	stack<int> m;
};

class MinQueue {
public:
	MinQueue() {}
	void push(int i) {
		first.push(i);
	}
	void pop() {
		if (second.size() != 0) {
			second.pop();
		} else {
			while (first.size() != 0) {
				second.push(first.get());
				first.pop();
			}
		}
	}
	int mmin() {
		if (second.size() == 0) {
			while (first.size() != 0) {
				second.push(first.get());
				first.pop();
			}
		}
		return second.mmin();
	}
private:
	MinStack first;
	MinStack second;
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n + 1, make_pair(1000000, 1000000));
	v[0] = make_pair(0, 0);
	int lst = 0;
	for (int i = 0; i < k; ++i) {
		int l, r;
		cin >> l >> r;
		vector<pair<int, int>> temp(n + 1, make_pair(1000000, 1000000));
		for (int j = n; j >= 0; --j) {
			if (j + l - lst <= n) {
				temp[j + l - lst].first = min(v[j].first, temp[j + l - lst].first);
				temp[j + l - lst].second = min(v[j].first + 1, temp[j + l - lst].second);
			}
			temp[j].first = min(v[j].second + 1, temp[j].first);
			temp[j].second = min(v[j].second, temp[j].second);
		}
		v = std::move(temp);
		temp = vector<pair<int, int>> (n + 1, make_pair(1000000, 1000000));
		MinQueue q1;
		MinQueue q2;
		for (int j = 0; j < min(r - l, n + 1); ++j) {
			q1.push(v[j].first);
			q2.push(v[j].second);
			temp[j].first = min(temp[j].first, q1.mmin() + 2);
			temp[j].first = min(temp[j].first, q2.mmin() + 1);
			temp[j].second = min(temp[j].second, q1.mmin() + 1);
			temp[j].second = min(temp[j].second, q2.mmin() + 2);
		}
		for (int j = r - l; j <= n; ++j) {
			q1.push(v[j].first);
			q2.push(v[j].second);
			temp[j].first = min(temp[j].first, q1.mmin() + 2);
			temp[j].first = min(temp[j].first, q2.mmin() + 1);
			temp[j].second = min(temp[j].second, q1.mmin() + 1);
			temp[j].second = min(temp[j].second, q2.mmin() + 2);
			q1.pop();
			q2.pop();
		}
		for (int j = n; j >= 0; --j) {
			if (j + r - l <= n) {
				temp[j + r - l].first = min(v[j].first, temp[j + r - l].first);
				temp[j + r - l].second = min(v[j].first + 1, temp[j + r - l].second);
			}
			temp[j].first = min(v[j].second + 1, temp[j].first);
			temp[j].second = min(v[j].second, temp[j].second);
		}
		v = std::move(temp);
        lst = r;
	}
    vector<pair<int, int>> temp(n + 1, make_pair(1000000, 1000000));
    int r = 2 * n;
    int l = lst;
    for (int j = n; j >= 0; --j) {
        if (j + r - l <= n) {
            temp[j + r - l].first = min(v[j].first, temp[j + r - l].first);
            temp[j + r - l].second = min(v[j].first + 1, temp[j + r - l].second);
        }
        temp[j].first = min(v[j].second + 1, temp[j].first);
        temp[j].second = min(v[j].second, temp[j].second);
    }
	if (temp[n].first == 1000000 && temp[n].second == 1000000) {
		cout << "Hungry\n";
	} else {
		cout << "Full\n";
		cout << min(temp[n].first, temp[n].second) << endl;
	}
	return 0;
}
