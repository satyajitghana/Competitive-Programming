#include <iostream>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    std::cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        std::string num;
        std::cin >> num;
        for (int i = num.length() - 1; i > 0; --i) {
            if (num[i] < num[i - 1]) {
                for (int j = i - 1; j >= 0; --j) {
                    if (num[j] == '0') {
                        num[j] = '9';
                    } else {
                        --num[j];
                        break;
                    }
                }
                for (int j = i; j < num.length(); ++j) {
                    num[j] = '9';
                }
            }
        }
        if (num[0] == '0') {
            num.erase(0, 1);
        }
        std::cout << "Case #" << test << ": " << num << std::endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}