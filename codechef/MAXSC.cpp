#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int find_max(vector <vector <int>> score) {
	int i = score.size()-1;
	while(i > 0) {
		if (score.at(i-1).size() == 0) return -1;
		int curr_element = score.at(i).front();
		int prev_element = score.at(i-1).front();
		if (!((prev_element < curr_element) && (prev_element != curr_element))) {
			score.at(i-1).erase(score.at(i-1).begin());
			i++;
		}
		i--;
	}
	return 0;
}

int find_sum(vector <vector <int>> scores) {
	int sum = 0;
	for (int i = 0; i < scores.size(); i++) {
		sum += scores.at(i).front();
	}
	return sum;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		vector <vector <int>> score;
		int N;
		cin >> N;
		for (int i = 0 ; i < N ; i++) {
			vector <int> curr_scores;
			for (int j = 0 ; j < N ; j++) {
				int score;
				cin >> score;
				curr_scores.push_back(score);
			}
			sort(curr_scores.begin(), curr_scores.end(), greater<int>());
			score.push_back(curr_scores);
		}
		int status = find_max(score);
		if (status == -1) cout << -1 << endl;
		else {
			cout << find_sum(score) << endl;
		}
	}
}
