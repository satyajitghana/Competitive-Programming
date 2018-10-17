#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int64_t pr = a;
        pr *= b;
        int64_t l = 1;
        int64_t r = 1000001;
        while (l + 1 < r) {
            int64_t m = (l + r) / 2;
            if (m * m * m <= pr) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l * l * l == pr && a % l == 0 && b % l == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}