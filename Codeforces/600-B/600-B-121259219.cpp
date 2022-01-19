//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	FIO;
	ll n, k, x;
	cin >> n >> k;
	ll a[n],b[k];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < k; ++i) {
		cin >> b[i];
	}
	sort(a, a + n);
	for (int i = 0; i < k; ++i) {
		x = b[i];
		x = upper_bound(a, a + n, x) - a;
		cout << x << " ";
	}
	cout << endl;
	return 0;
}