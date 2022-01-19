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
	int n, d, a = 0, b = 0;
	ll _max = 0, c = 0;
	cin >> n >> d;
	pair<int, int> arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		arr[i] = { a, b };
	}
	a = 0, b = 1;
	sort(arr, arr + n);
	c = arr[0].second;
	_max = c;
	while (b < n) {
		if (arr[b].first - arr[a].first < d) {
			c += arr[b].second;
			b++;
		} else {
			c -= arr[a].second;
			a++;
		}
		_max = max(_max, c);
	}
	cout << _max << endl;

	return 0;
}