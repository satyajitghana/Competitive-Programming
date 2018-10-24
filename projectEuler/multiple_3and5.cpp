#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() { unsigned long int T, i, N, p, sum;

scanf("%lld", &T);
for(i = 0; i < T; i++)
    {
    scanf("%lld\n", &N);
    sum = 0;
    p = (N-1)/3;
    sum = ((3*p*(p+1))/2);

    p = (N-1)/5;
    sum = sum + ((5*p*(p+1))/2);

    p = (N-1)/15;
    sum = sum - ((15*p*(p+1))/2);
    printf("%lld\n", sum);
    }
/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
return 0;

}
