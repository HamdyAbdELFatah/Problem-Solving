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
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	if (n % 4 != 0) {
		int needed = 4 - (n % 4);
		if (needed > 2)
			needed = min(c, min(a * 3, b + a));
		else if (needed > 1)
			needed = min(a * 2, min(b, c * 2));
		else
			needed = min(a, min(b + c, c * 3));
		cout << needed << endl;
	} else
		cout << 0 << endl;

	return 0;
}