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
	int n, t, a = 0, b = 0, _max = 0;
	cin >> n >> t;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	while (b < n) {
		if (t - arr[b] >= 0) {
			t -= arr[b];
			b++;
		} else {
			t += arr[a];
			a++;
		}
		_max = max(_max, b - a);
	}
	cout << _max << endl;

	return 0;
}