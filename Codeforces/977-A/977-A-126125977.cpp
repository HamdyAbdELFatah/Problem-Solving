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
double distance(ll x1, ll y1, ll x2, ll y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

int main() {
	FIO;
	int n, k;
	cin >> n >> k;
	while (k--) {
		if (n % 10 == 0)
			n /= 10;
		else
			n--;
	}
	cout << n << endl;
	return 0;
}