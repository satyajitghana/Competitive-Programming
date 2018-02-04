#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long N,C,D,S;
		cin >> N;
		vector <long> time(N);
		for (int i = 0 ; i < N; i++) {
			cin >> time[i];
		}
		cin >> C >> D >> S;
		//sort(time.begin(), time.end());
		long max = time[0];
		for (int i = 1 ; i < N ; i++) {
			if (time[i] > max) max = time[i];
		}
		cout << (N-1) * max << ".000000000" << endl;
	}
}
