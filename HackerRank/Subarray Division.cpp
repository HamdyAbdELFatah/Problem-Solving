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
	int n, x, d, m, c = 0;
	cin >> n;
	int arr[n];
	cin >> arr[0];
	for (int i = 1; i < n; ++i) {
		cin >> x;
		arr[i] = x + arr[i - 1];
	}

	cin >> d >> m;
	for (int i = m - 1; i < n; ++i) {
		if (i - m >= 0 && arr[i] - arr[i - m] == d)
			c++;
		else if (i - m < 0 && arr[i] == d){
			c++;
		}
	}
	cout << c << endl;
	return 0;
}
