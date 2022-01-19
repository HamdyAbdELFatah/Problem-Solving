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
int n, m, k, c = 0;
bool valid(int i, int j) {
	if (i <= m && i > 0 && j <= n && j > 0)
		return true;
	return false;
}
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<vector<char>> arr;
vector<vector<int>> visit;
int turn = 1;
void dfs(int v, int u) {
	visit[v][u] = turn;
	int flag = 0;
	for (int i = 0; i < 4; ++i) {
		if (valid(v + dy[i], u + dx[i]) && arr[v + dy[i]][u + dx[i]] == '.'
				&& visit[v + dy[i]][u + dx[i]] < turn) {
			dfs(v + dy[i], u + dx[i]);
			flag++;
		}
	}
	for (int i = 0; i < 4 && k > 0; ++i) {
		if (valid(v + dy[i], u + dx[i]) && arr[v + dy[i]][u + dx[i]] == 'X'&&arr[v][u] != 'X') {
			arr[v][u] = 'X';
			k--;
			flag = 1;
		}
	}
	if (flag == 0 && k > 0) {
		arr[v][u] = 'X';
		k--;
	}
}
int main() {
	fast();
	int a = -1, b = -1;
	cin >> m >> n >> k;
	arr.resize(m + 1, vector<char>(n + 1));
	visit.resize(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == '.' && a == -1) {
				a = i;
				b = j;
				c++;
			}
		}
	}
	dfs(a, b);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}