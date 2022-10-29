#include <iostream>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int rows, cols;
        cin >> rows >> cols;
        cout << "Case #" << test << ":" << endl;
        for (int row = 0; row <= 2 * rows; ++row) {
            for (int col = 0; col <= 2 * cols; ++col) {
                if (row < 2 && col < 2 || row % 2 + col % 2 == 2) {
                    cout << ".";
                } else if (row % 2 + col % 2 == 0) {
                    cout << "+";
                } else if (row % 2 == 0) {
                    cout << "-";
                } else {
                    cout << "|";
                }
            }
            cout << endl;
        }
    }
}
