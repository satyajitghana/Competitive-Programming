#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>

int main() {
    std::vector<std::vector<int8_t>> test_cases = {
        {4, 7, 6, 1, 0, 3},
        {0, 1, 3, 4, 6, 7},
        {4, 2, 1, 3},
        {2, 3, 0, 0, 7, 7, 4, 5, 11, 11}
    };

    std::vector<int8_t> solutions = {5, 0, 6, 2};

    auto msb = [](int v) {
        unsigned r = 0;
        while (v >>= 1) {
            r++;
        }
        return r;
    };

    std::for_each(test_cases.begin(), test_cases.end(), [index = 0, &solutions, &msb] (auto &test_case) mutable {
        int solution = 0;
        for (auto it = test_case.cbegin(); it != test_case.end() && std::next(it) != test_case.end(); ++it) {
            auto&& [first, second] = std::tie(*it, *std::next(it));
            if (first > second and not first ^ second) {
                // needs sorting
                auto bit_idx = msb(first ^ second);
                solution |= 1 << bit_idx;
            }
        }

        std::cout
            << "test case [" << index << "] :: "
            << ((solution == solutions[index]) ? "PASSED" : "FAILED")
            << std::endl;

        index++;
    });
}
