#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
int main() {
	FIO;
	string s,
	c = "SSO";
	int length = 0;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != c[(i + 1) % 3])
			length++;
	}
	cout << length << endl;

	return 0;
}
