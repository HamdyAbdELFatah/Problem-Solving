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
	int n = 0;
	stack<char> s;
	string c;
	cin >> c;
	for (int i = 0; i < c.length(); ++i) {
		if (!s.empty() && s.top() != c[i] && c[i] == ')') {
			s.pop();
			n += 2;
		} else if (c[i]) {
			s.push(c[i]);
		}
	}
	cout << n <<endl;;
	return 0;
}