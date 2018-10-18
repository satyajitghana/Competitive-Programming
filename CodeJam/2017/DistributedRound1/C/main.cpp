#include <iostream>
#include <vector>
#include <algorithm>
#include "weird_editor.h"
#include "message.h"

using namespace std;

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    long long len = GetNumberLength();
    long long pos = MyNodeId();
    long long num = NumberOfNodes();
    if (len < num) {
        vector<int> v(10);
        for (int i = 0; i < len; ++i) {
            int digit = GetDigit(i);
            for (int j = 0; j < digit; ++j) {
                v[j] = 0;
            }
            ++v[digit];
        }
        int j = 9;
        long long mod = 1000 * 1000 * 1000 + 7;
        long long ans = 0;
        for (int i = 0; i < len; ++i) {
            ans *= 10;
            while (j > 0 && v[j] == 0) {
                --j;
            }
            if (v[j] != 0) {
                ans += j;
                --v[j];
            }
            ans %= mod;
        }
        if (pos == 0) {
            cout << ans;
        }
    } else {
        vector<int> v(10);
        for (int i = (len * pos) / num; i < (len * (pos + 1)) / num; ++i) {
            int digit = GetDigit(i);
            for (int j = 0; j < digit; ++j) {
                v[j] = 0;
            }
            ++v[digit];
        }
        if (pos != 0) {
            for (int i = 0; i < 10; ++i) {
                PutInt(0, v[i]);
            }
            Send(0);
            Receive(0);
            for (int i = 9; i >= 0; --i) {
                v[i] = GetInt(0);
            }
        } else {
            for (int i = 1; i < num; ++i) {
                Receive(i);
                vector<int> temp_v(10);
                int max_temp = 0;
                for (int j = 0; j < 10; ++j) {
                    temp_v[j] = GetInt(i);
                    if (temp_v[j] != 0) {
                        max_temp = j;
                    }
                }
                for (int j = 0; j < max_temp; ++j) {
                    v[j] = 0;
                }
                for (int j = 0; j < 10; ++j) {
                    v[j] += temp_v[j];
                }
            }
            vector<int> temp_v(10);
            for (int j = 0; j < 10; ++j) {
                temp_v[j] = v[j];
                v[j] = 0;
            }
            long long size = len / num;
            for (int j = 9; j >= 0; --j) {
                v[j] = min(temp_v[j], size);
                size -= v[j];
                temp_v[j] -= v[j];
            }
            for (int i = 1; i < num; ++i) {
                size = (len * (i + 1)) / num - (len * i) / num;
                vector<int> vv(10);
                for (int j = 9; j >= 0; --j) {
                    vv[j] = min(temp_v[j], size);
                    size -= vv[j];
                    temp_v[j] -= vv[j];
                    PutInt(i, vv[j]);
                }
                Send(i);
            }
        }
        int j = 9;
        long long mod = 1000 * 1000 * 1000 + 7;
        long long ans = 0;
        long long ten = 1;
        long long size = (len * (pos + 1)) / num - (len * pos) / num;
        for (int i = 0; i < size; ++i) {
            ans *= 10;
            ten *= 10;
            while (j > 0 && v[j] == 0) {
                --j;
            }
            if (v[j] != 0) {
                ans += j;
                --v[j];
            }
            ans %= mod;
            ten %= mod;
        }
        if (pos != 0) {
            PutLL(0, ten);
            PutLL(0, ans);
            Send(0);
        } else {
            for (int i = 1; i < num; ++i) {
                Receive(i);
                ans *= GetLL(i);
                ans %= mod;
                ans += GetLL(i);
                ans %= mod;
            }
            cout << ans << endl;
        }
    }
    return 0;
}