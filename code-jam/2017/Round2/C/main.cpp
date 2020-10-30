#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("output", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int r, c;
        cin >> r >> c;
        vector<string> map(r);
        for (int i = 0; i < r; ++i) {
            cin >> map[i];
        }
        bool possible = true;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == '|' || map[i][j] == '-') {
                    bool gor_possible = true;
                    int temp_j = j - 1;
                    while (temp_j >= 0) {
                        if (map[i][temp_j] == '#') {
                            break;
                        }
                        if (map[i][temp_j] == '|' || map[i][temp_j] == '-' || map[i][temp_j] == '+') {
                            gor_possible = false;
                            break;
                        }
                        --temp_j;
                    }
                    temp_j = j + 1;
                    while (temp_j < c) {
                        if (map[i][temp_j] == '#') {
                            break;
                        }
                        if (map[i][temp_j] == '|' || map[i][temp_j] == '-' || map[i][temp_j] == '+') {
                            gor_possible = false;
                            break;
                        }
                        ++temp_j;
                    }
                    bool vert_possible = true;
                    int temp_i = i - 1;
                    while (temp_i >= 0) {
                        if (map[temp_i][j] == '#') {
                            break;
                        }
                        if (map[temp_i][j] == '|' || map[temp_i][j] == '-' || map[temp_i][j] == '+') {
                            vert_possible = false;
                            break;
                        }
                        --temp_i;
                    }
                    temp_i = i + 1;
                    while (temp_i < r) {
                        if (map[temp_i][j] == '#') {
                            break;
                        }
                        if (map[temp_i][j] == '|' || map[temp_i][j] == '-' || map[temp_i][j] == '+') {
                            vert_possible = false;
                            break;
                        }
                        ++temp_i;
                    }
                    if (vert_possible) {
                        if (gor_possible) {
                            map[i][j] = '+';
                        } else {
                            map[i][j] = '|';
                        }
                    } else {
                        if (gor_possible) {
                            map[i][j] = '-';
                        } else {
                            possible = false;
                            break;
                        }
                    }
                }
            }
            if (!possible) {
                break;
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == '.') {
                    bool gor_possible = false;
                    int temp_j = j - 1;
                    int get_j;
                    while (temp_j >= 0) {
                        if (map[i][temp_j] == '#' || map[i][temp_j] == '|') {
                            break;
                        }
                        if (map[i][temp_j] == '-' || map[i][temp_j] == '+') {
                            gor_possible = true;
                            get_j = temp_j;
                            break;
                        }
                        --temp_j;
                    }
                    temp_j = j + 1;
                    while (temp_j < c) {
                        if (map[i][temp_j] == '#' || map[i][temp_j] == '|') {
                            break;
                        }
                        if (map[i][temp_j] == '-' || map[i][temp_j] == '+') {
                            gor_possible = true;
                            get_j = temp_j;
                            break;
                        }
                        ++temp_j;
                    }
                    bool vert_possible = false;
                    int temp_i = i - 1;
                    int get_i;
                    while (temp_i >= 0) {
                        if (map[temp_i][j] == '#' || map[temp_i][j] == '-') {
                            break;
                        }
                        if (map[temp_i][j] == '|' || map[temp_i][j] == '+') {
                            vert_possible = true;
                            get_i = temp_i;
                            break;
                        }
                        --temp_i;
                    }
                    temp_i = i + 1;
                    while (temp_i < r) {
                        if (map[temp_i][j] == '#' || map[temp_i][j] == '-') {
                            break;
                        }
                        if (map[temp_i][j] == '|' || map[temp_i][j] == '+') {
                            vert_possible = true;
                            get_i = temp_i;
                            break;
                        }
                        ++temp_i;
                    }
                    if (vert_possible) {
                        if (!gor_possible) {
                            map[get_i][j] = '|';
                        }
                    } else {
                        if (gor_possible) {
                            map[i][get_j] = '-';
                        } else {
                            possible = false;
                            break;
                        }
                    }
                }
            }
            if (!possible) {
                break;
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == '.') {
                    bool gor_possible = false;
                    bool gor_get = false;
                    int temp_j = j - 1;
                    int get_j;
                    while (temp_j >= 0) {
                        if (map[i][temp_j] == '#' || map[i][temp_j] == '|') {
                            break;
                        }
                        if (map[i][temp_j] == '-' || map[i][temp_j] == '+') {
                            if (map[i][temp_j] == '-') {
                                gor_get = true;
                            }
                            gor_possible = true;
                            get_j = temp_j;
                            break;
                        }
                        --temp_j;
                    }
                    temp_j = j + 1;
                    while (temp_j < c) {
                        if (map[i][temp_j] == '#' || map[i][temp_j] == '|') {
                            break;
                        }
                        if (map[i][temp_j] == '-' || map[i][temp_j] == '+') {
                            if (map[i][temp_j] == '-') {
                                gor_get = true;
                            }
                            gor_possible = true;
                            get_j = temp_j;
                            break;
                        }
                        ++temp_j;
                    }
                    bool vert_possible = false;
                    bool vert_get = false;
                    int temp_i = i - 1;
                    int get_i;
                    while (temp_i >= 0) {
                        if (map[temp_i][j] == '#' || map[temp_i][j] == '-') {
                            break;
                        }
                        if (map[temp_i][j] == '|' || map[temp_i][j] == '+') {
                            if (map[temp_i][j] == '|') {
                                vert_get = true;
                            }
                            vert_possible = true;
                            get_i = temp_i;
                            break;
                        }
                        --temp_i;
                    }
                    temp_i = i + 1;
                    while (temp_i < r) {
                        if (map[temp_i][j] == '#' || map[temp_i][j] == '-') {
                            break;
                        }
                        if (map[temp_i][j] == '|' || map[temp_i][j] == '+') {
                            if (map[temp_i][j] == '|') {
                                vert_get = true;
                            }
                            vert_possible = true;
                            get_i = temp_i;
                            break;
                        }
                        ++temp_i;
                    }
                    if (!gor_get && !vert_get) {
                        if (vert_possible) {
                            map[get_i][j] = '|';
                        } else if (gor_possible) {
                            map[i][get_j] = '-';
                        } else {
                            possible = false;
                            break;
                        }
                    }
                }
            }
            if (!possible) {
                break;
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == '+') {
                    map[i][j] = '|';
                }
            }
        }
        if (!possible) {
            cout << "Case #" << test << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << test << ": POSSIBLE" << endl;
            for (int i = 0; i < r; ++i) {
                cout << map[i] << endl;
            }
        }
    }
    return 0;
}