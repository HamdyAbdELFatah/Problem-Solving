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

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool valid(int x, int y, int n, int m) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int main() {
	fast();
	int n, m, mx = 0;
	cin >> n >> m;
	char arr[n][m];
	int visit[n][m];
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visit[i][j] = -1;
			cin >> arr[i][j];
			if (arr[i][j] == '#') {
				q.push( { i, j });
				visit[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = u.first + dx[i], y = u.second + dy[i];
			if (valid(x, y, n, m) && visit[x][y] == -1) {
				visit[x][y] = visit[u.first][u.second] + 1;
				mx = max(mx, visit[x][y]);
				q.push( { x, y });
			}
		}
	}
	cout << mx << endl;
	return 0;
}