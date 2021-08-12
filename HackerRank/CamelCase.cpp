#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
int main() {
	FIO;
	int c = 1;
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); ++i) {
		if (isupper(s[i]))
			c++;
	}
	cout << c << endl;
	return 0;
}
