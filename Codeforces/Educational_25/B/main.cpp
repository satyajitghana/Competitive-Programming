#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> field(10);
    for (int i = 0; i < 10; ++i) {
        cin >> field[i];
    }
    int dir[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1},
                     {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (field[i][j] == '.') {
                for (int l = 0; l < 4; ++l) {
                    int k = 0;
                    for (int n = 1; n < 5; ++n) {
                        if (i + n * dir[l][0] >= 0 && i + n * dir[l][0] < 10 && j + n * dir[l][1] >= 0 && j + n * dir[l][1] < 10) {
                            if (field[i + n * dir[l][0]][j + n * dir[l][1]] == 'X') {
                                ++k;
                            } else {
                                break;
                            }
                        }
                    }
                    for (int n = 1; n < 5; ++n) {
                        if (i + n * dir[l + 4][0] >= 0 && i + n * dir[l + 4][0] < 10 && j + n * dir[l + 4][1] >= 0 && j + n * dir[l + 4][1] < 10) {
                            if (field[i + n * dir[l + 4][0]][j + n * dir[l + 4][1]] == 'X') {
                                ++k;
                            } else {
                                break;
                            }
                        }
                    }
                    if (k >= 4) {
                        cout << "YES\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}