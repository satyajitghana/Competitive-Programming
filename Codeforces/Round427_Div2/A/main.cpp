#include <iostream>

using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    if (v1 * s + 2 * t1 < v2 * s + 2 * t2) {
        cout << "First\n";
    } else if (v1 * s + 2 * t1 > v2 * s + 2 * t2) {
        cout << "Second\n";
    } else {
        cout << "Friendship\n";
    }
    return 0;
}