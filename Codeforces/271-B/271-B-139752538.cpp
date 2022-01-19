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
	int n, m, x, y, p = 200001, miny = p, c = 0;
	cin >> n >> m;
	int arr[n][m];
	int memo[p] = { 0 };
	int seive[p] = { 0 };
	seive[1] = 1;
	for (int i = 2; i < p; ++i) {
		if (seive[i] == 0) {
			for (int j = 2; i * j < p; ++j) {
				seive[i * j] = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		c = 0;
		for (int j = 0; j < m; ++j) {
			cin >> x;
			arr[i][j] = x;
			y = x;
			if (memo[y] == 0) {
				while (seive[y] != 0) {
					y++;
					memo[x]++;
				}
			}
			c += memo[x];
		}
		miny = min(miny, c);
	}
	for (int i = 0; i < m; ++i) {
		c = 0;
		for (int j = 0; j < n; ++j) {
			x = arr[j][i];
			c += memo[x];
		}
		miny = min(miny, c);
	}
	cout << miny << endl;
	return 0;
}