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
	int n, m, x, c = 0, freq[100001] = { 0 };
	cin >> n >> m;
	int arr[n], po[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (freq[arr[i]] == 0)
			c++;
		freq[arr[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		po[i] = c;
		if (freq[arr[i]] == 1)
			c--;
		else
			freq[arr[i]]--;
	}
	for (int i = 0; i < m; ++i) {
		cin >> x;
		cout << po[x - 1] << endl;

	}

	return 0;
}