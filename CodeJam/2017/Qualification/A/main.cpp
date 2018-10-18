#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    std::cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        std::string pancakes;
        int flip_len;
        std::cin >> pancakes >> flip_len;
        int flip_count = 0;
        for (int cake_i = 0;
             cake_i < pancakes.length() - flip_len + 1; ++cake_i) {
            if (pancakes[cake_i] == '-') {
                ++flip_count;
                for (int cake_j = 0; cake_j < flip_len; ++cake_j) {
                    if (pancakes[cake_i + cake_j] == '-') {
                        pancakes[cake_i + cake_j] = '+';
                    } else {
                        pancakes[cake_i + cake_j] = '-';
                    }
                }
            }
        }
        for (int cake_i = pancakes.length() - flip_len + 1;
             cake_i < pancakes.length(); ++cake_i) {
            if (pancakes[cake_i] == '-') {
                flip_count = -1;
            }
        }
        if (flip_count == -1) {
            std::cout << "Case #" << test << ": IMPOSSIBLE" << std::endl;
        } else {
            std::cout << "Case #" << test << ": " << flip_count << std::endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}