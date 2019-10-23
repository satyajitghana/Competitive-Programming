#include <bits/stdc++.h>
using namespace std;
 
char change(char ch)
{
    return (ch == 'R') ? 'G' : 'R';
}
 
int cherryWith(string str, char myCherry)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != myCherry) {
		if (str[i] == 'R') sum += 5;
		else sum += 3;
	}
 
        myCherry = change(myCherry);
    }
    return sum;
}
 
int main() {
	int T;
	cin >> T;
	while (T--) {
		int sum = 0;
		int N;
		cin >> N;
		int BS;
		cin >> BS;
		while (N--) {
			string str;
			cin >> str;
			sum += 	min(cherryWith(str, 'R'),
               cherryWith(str, 'G'));
		
		}
		cout << sum << endl;
	}
    return 0;
}
