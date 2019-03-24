#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
#define mod 1000000007
using namespace boost::multiprecision;
using namespace std;
#define pb push_back

using namespace std;

int main()
{

    cpp_int T;
    cin >> T;

    while (T--)
    {
        string home_team, away_team, blank;
        cpp_int ht_goals, at_goals;
        map<string, cpp_int> match1, match2;

        for (int i = 0; i < 12; i++)
        {

            cin >> home_team >> ht_goals >> blank >> at_goals >> away_team;

            if (ht_goals > at_goals)
            {
                match1[home_team] += 3;
                match2[home_team] += ht_goals - at_goals;
                match2[away_team] += at_goals - ht_goals;
            }

            else if (at_goals > ht_goals)
            {
                match1[away_team] += 3;
                match2[away_team] += at_goals - ht_goals;
                match2[home_team] += ht_goals - at_goals;
            }

            else
            {
                match1[away_team] += 1;
                match1[home_team] += 1;
            }
        }

        vector<pair<cpp_int, pair<cpp_int, string>>> vec;

        for (auto it = match1.begin(); it != match1.end(); it++)
        {
            vec.pb(make_pair((*it).second, make_pair(match2[(*it).first], (*it).first)));
        }

        sort(vec.begin(), vec.end());

        cout << vec[vec.size() - 1].second.second << " " << vec[vec.size() - 2].second.second << endl;
    }

    return 0;
}