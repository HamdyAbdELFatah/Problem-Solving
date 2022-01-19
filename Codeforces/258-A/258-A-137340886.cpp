//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FastIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define endl "\n"
#define INFL LLONG_MAX
using namespace std;
void fast() {
	FastIO;
}
int main() {
	fast();
	int x = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			x = i;
			break;
		}

	}
	for (int i = 0; i < s.size(); ++i) {
		if (i != x) {
			cout << s[i];
		}
	}
	cout << endl;

	return 0;
}