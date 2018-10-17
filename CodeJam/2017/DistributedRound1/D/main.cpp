#include <iostream>
#include "todd_and_steven.h"
#include "message.h"

using namespace std;

int main() {
    long long todd_len = GetToddLength();
    long long stev_len = GetStevenLength();
    long long t = 0;
    long long s = 0;
    long long j = 0;
    long long sum = 0;
    long long mod = 1000 * 1000 * 1000 + 7;
    while (t < todd_len || s < stev_len) {
        if (s == stev_len) {
            sum += j ^ GetToddValue(t);
            ++t;
        } else if (t == todd_len) {
            sum += j ^ GetStevenValue(s);
            ++s;
        } else if (GetToddValue(t) < GetStevenValue(s)) {
            sum += j ^ GetToddValue(t);
            ++t;
        } else {
            sum += j ^ GetStevenValue(s);
            ++s;
        }
        ++j;
        sum %= mod;
    }
    if (MyNodeId() == 0) {
        cout << sum;
    }
    return 0;
}