#include <iostream>
#include "message.h"
#include "query_of_death.h"

using namespace std;

int main() {
    if (MyNodeId() % 2 == 0) {
        int sum = 0;
        int n = GetLength();
        int last_i = 0;
        for (int i = (n / (MyNodeId() / 2)); i < n / ((MyNodeId() + 2) / 2); ++i) {
            int last = GetValue(i);
            last_i = i;
            sum += last;
            bool good = true;
            for (int j = 0; j < 50; ++j) {
                if (last != GetValue(i)) {
                    good = false;
                    break;
                }
            }
            if (!good) {
                break;
            }
        }
        PutInt(MyNodeId() + 1, last_i);
        PutInt(MyNodeId() + 1, sum);
        Send(MyNodeId() + 1);
    } else {
        Receive(MyNodeId() - 1);
        int last_i = GetInt(MyNodeId() - 1);
        int sum = GetInt(MyNodeId() - 1);
        int n = GetLength();
        for (int i = last_i + 1; i < n / ((MyNodeId() + 1) / 2); ++i) {
            sum += GetValue(i);
        }
        PutInt(0, sum);
        Send(0);
    }
    if (MyNodeId() == 0) {
        int sum = 0;
        for (int i = 1; i < NumberOfNodes(); i += 2) {
            Receive(i);
            sum += GetInt(i);
        }
        cout << sum;
    }
    return 0;
}