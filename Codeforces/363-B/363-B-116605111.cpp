//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int fr[26];
int main() {
	FIO;
	int n,
	k, m = INF, index = 0;
	cin >> n >> k;
	int arr[n + 1];
	arr[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = k; i <= n; ++i) {
		if (m > arr[i] - arr[i - k]) {
			m = arr[i] - arr[i - k];
			index = i - k + 1;
		}
	}
	cout << index << endl;
	return 0;
}