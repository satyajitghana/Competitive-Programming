#include <iostream>

using namespace std;

int main() {
int64_t A, B, x, y, z;
cin >> A >> B >> x >> y >> z;
A -= x * 2;
A -= y;
B -= y;
B -= 3 * z;
A = max((int64_t) 0, -A);
B = max((int64_t) 0, -B);
cout << A + B << endl;
return 0;
}
