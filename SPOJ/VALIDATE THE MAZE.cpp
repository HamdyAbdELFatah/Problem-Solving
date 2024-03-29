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
int n, m, c = 0;
bool valid(int i, int j) {
	if (i <= m && i > 0 && j <= n && j > 0)
		return true;
	return false;
}
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<vector<char>> arr;
vector<vector<int>> visit;
void dfs(int v, int u) {
	visit[v][u] = 1;
	for (int i = 0; i < 4; ++i) {
		if (valid(v + dy[i], u + dx[i]) && arr[v + dy[i]][u + dx[i]] == '.'
				&& visit[v + dy[i]][u + dx[i]] == 0) {
			if ((v + dy[i] == m || v + dy[i] == 1 || u + dx[i] == n
					|| u + dx[i] == 1)) {
				c++;
			}
			dfs(v + dy[i], u + dx[i]);
		}
	}
}
int main() {
	fast();
	int t;
	cin >> t;
	while (t--) {
		int a = -1, b = -1;
		cin >> m >> n;
		arr.resize(m + 1, vector<char>(n + 1));
		visit.resize(m + 1, vector<int>(n + 1));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == '.' && (i == m || i == 1 || j == n || j == 1)
						&& a == -1) {
					a = i;
					b = j;
					c++;
				}
			}
		}

		if (a != -1)
			dfs(a, b);
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (arr[i][j] == '.' && (i == m || i == 1 || j == n || j == 1)
						&& visit[i][j] == 0) {
					c = 100;
				}
			}
		}
		if (c == 2)
			cout << "valid" << endl;
		else
			cout << "invalid" << endl;
		c = 0;
		arr.clear();
		visit.clear();
	}
	return 0;
}

