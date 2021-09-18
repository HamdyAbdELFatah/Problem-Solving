//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FastIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
void fast() {
	FastIO;
}
int main() {
	fast();
	int n, m, x, y, c = 0, t = 0;
	cin >> n >> m;
	int arr[n][n] = { 0 };
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		arr[x - 1][y - 1] = 1;
		arr[y - 1][x - 1] = 1;

	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 1) {
				c++;
			}
		}
		if (c == 1)
			t++;
		c = 0;
	}
	cout << t << endl;
	return 0;
}

