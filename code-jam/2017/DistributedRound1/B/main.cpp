#include <iostream>
#include "pancakes.h"
#include "message.h"

int main() {
    long long m = GetStackSize();
    long long n = GetNumDiners();
    long long k = 1;
    long long u = 0;
    long long pos = MyNodeId();
    long long num = NumberOfNodes();
    if (m > num) {
        for (long long i = (m * pos) / num; i < (m * (pos + 1)) / num; ++i) {
            long long a = GetStackItem(i);
            if (a < u) {
                ++k;
            }
            u = a;
        }
        if (pos + 1 != num) {
            if (GetStackItem((m * (pos + 1)) / num) >=
                GetStackItem((m * (pos + 1)) / num - 1)) {
                --k;
            }
        }
        if (pos == 0) {
            for (int i = 1; i < num; ++i) {
                Receive(i);
                k += GetLL(i);
            }
            std::cout << k;
        } else {
            PutLL(0, k);
            Send(0);
        }
    } else if (pos == 0) {
        for (int i = 0; i < m; ++i) {
            int a = GetStackItem(i);
            if (a < u) {
                ++k;
            }
            u = a;
        }
        std::cout << k << std::endl;
    }
    return 0;
}