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
	int n, m, x0 = 0, x1 = 0, ys1 = 0,ye1=0, f = 0;

	char c;
	cin >> n >> m;
	vector<vector<char>> v(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> c;
			v[i].push_back(c);
			if (c == '*' && f == 0) {
				x0 = i;
				x1 = i;
				ys1 = j;
				ye1 = j;
				f = 1;
			} else if (c == '*') {
				x1 = i;
				ys1 = min(ys1, j);
				ye1 = max(j, ye1);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		int x = 0;
		for (int j = 0; j < m; ++j) {
			if (i < x0 || i > x1)
				continue;
			if (j < ys1 || j > ye1)
				continue;
			cout << v[i][j];
			x++;
		}
		if (x > 0)
			cout << endl;
	}
	return 0;
}