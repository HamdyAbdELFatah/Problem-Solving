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
	int n, m, a, b, f = 0, c = 0;
	cin >> n >> m;
	int visit[n + 1] = { 0 };
	vector<vector<int>> v(n + 1, vector<int>(1, 0));
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[a][0]++;
		v[b].push_back(a);
		v[b][0]++;
	}
	while (true) {
		for (int i = 1; i <= n; ++i) {
			if (visit[i] == 0) {
				visit[i] = 1;
				if (v[i][0] == 1) {
					visit[i] = -1;
				}
			}
		}
		f = 0;
		int t = c;
		for (int i = 1; i <= n; ++i) {
			if (v[i][0] >= 1 && visit[i] != -2 && visit[i] != 0) {
				for (int j = 1; j < v[i].size(); ++j) {
					if (visit[v[i][j]] == -1) {
						visit[v[i][j]] = -2;
						v[i][0]--;
						if (f == 0) {
							c++;
							f = 1;
						}
					}
				}
			}
		}
		for (int j = 1; j <= n; ++j) {
			if (visit[j] != -1 && visit[j] != -2)
				visit[j] = 0;
		}
		if (t == c)
			break;
	}
	cout << c << endl;

	return 0;
}