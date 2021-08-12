//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
int main() {
	FIO;
	string text = "hackerrank";
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int c = 0;
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] == text[c] && c < 10)
				c++;
		}
		if(c==10)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}

	return 0;
}
