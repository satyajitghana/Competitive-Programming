#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

long double square (long double x1, long double h1, long double x2, long double h2) {
    long double answer = 0;
    if (h2 > h1) {
        long double temp = h2 - h1;
        answer += temp * temp / 2;
        answer += temp * h1;
        h2 = h1;
        x2 -= temp;
    }
    if (h1 > h2) {
        long double temp = h1 - h2;
        answer += temp * temp / 2;
        answer += temp * h2;
        h1 = h2;
        x1 += temp;
    }
    long double temp = x2 - x1;
    temp /= 2;
    if (temp > h1) {
        temp = h1;
    }
    answer += temp * temp;
    answer += temp * (h1 - temp) * 2;
    return answer;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        int n;
        cin >> n;
        long long ax, bx, cx, x;
        cin >> x >> ax >> bx >> cx;
        long long ah, bh, ch, h;
        cin >> h >> ah >> bh >> ch;

        long double answer = 0;
        long double sum = 0;

        set<pair<long double, long double>> s;
        s.insert(pair<long double, long double> (x, h));
        sum = h;
        sum *= sum;
        answer += sum;

        while (--n > 0) {
            x = (ax * x + bx) % cx + 1;
            h = (ah * h + bh) % ch + 1;
            if (s.find(pair<long double, long double> (x, h)) != s.end()) {
                answer += sum;
                continue;
            }

            s.insert(pair<long double, long double> (x, h));

            set<pair<long double, long double>>::iterator it = s.find(pair<long double, long double> (x, h));
            set<pair<long double, long double>>::iterator l = it;
            --l;
            set<pair<long double, long double>>::iterator r = it;
            ++r;
            long double oldh = 0;
            if (it != s.begin()) {
                oldh = max(l->second - (it->first - l->first), (long double) 0);
            }
            if (r != s.end()) {
                oldh = max(oldh, r->second - (r->first - it->first));
            }
            if (it != s.begin()) {
                if (l->second - it->second >= it->first - l->first) {
                    s.erase(it);
                    answer += sum;
                    continue;
                }
            }
            if (r != s.end()) {
                if (r->second - it->second >= r->first - it->first) {
                    s.erase(it);
                    answer += sum;
                    continue;
                }
            }
            if (it != s.begin()) {
                sum -= square(l->first, l->second, it->first, oldh);
                long double ooldx = l->first;
                long double ooldh = l->second;
                while (it != s.begin() && it->second - l->second >= it->first - l->first) {
                    s.erase(l);
                    l = it;
                    --l;
                    if (it != s.begin()) {
                        sum -= square(l->first, l->second, ooldx, ooldh);
                        ooldx = l->first;
                        ooldh = l->second;
                    } else {
                        sum -= ooldh * ooldh / 2;
                    }
                }
            } else {
                sum -= oldh * oldh / 2;
            }
            if (r != s.end()) {
                sum -= square(it->first, oldh, r->first, r->second);
                long double ooldx = r->first;
                long double ooldh = r->second;
                while (r != s.end() && it->second - r->second >= r->first - it->first) {
                    s.erase(r);
                    r = it;
                    ++r;
                    if (r != s.end()) {
                        sum -= square(ooldx, ooldh, r->first, r->second);
                        ooldx = r->first;
                        ooldh = r->second;
                    } else {
                        sum -= ooldh * ooldh / 2;
                    }
                }
            } else {
                sum -= oldh * oldh / 2;
            }
            if (it != s.begin()) {
                sum += square(l->first, l->second, it->first, it->second);
            } else {
                sum += it->second * it->second / 2;
            }
            if (r != s.end()) {
                sum += square(it->first, it->second, r->first, r->second);
            } else {
                sum += it->second * it->second / 2;
            }
            answer += sum;
        }
        fixed(std::cout);
        cout << "Case #" << t << ": " << setprecision(10) << answer << endl;
    }


    return 0;
}