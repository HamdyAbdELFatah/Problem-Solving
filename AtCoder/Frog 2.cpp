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
	int n,
	k;
	cin >> n >> k;
	int arr[n], value[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	value[1] = abs(arr[1] - arr[0]);
	value[0] = 0;
	for (int i = 2; i < n; ++i) {
		value[i]=INF;
		for (int j = 1; j <= k && j <= i; ++j) {
			value[i] = min(abs(arr[i] - arr[i - j]) + value[i - j], value[i]);
		}
	}
	cout <<value[n - 1] << endl;
	return 0;
}
