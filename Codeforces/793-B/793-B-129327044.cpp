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
int n, m, turn = 2;
bool valid(int i, int j) {
	if (i <= m && i > 0 && j <= n && j > 0)
		return true;
	return false;
}
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
vector<vector<char>> arr;
vector<vector<pair<int, int>>> visit;
string result = "NO";
void dfs(int v, int u, int d) {
	visit[v][u].first = d;
	visit[v][u].second = turn;
	for (int i = 0; i < 4; ++i) {
		if (valid(v + dy[i], u + dx[i])
				&& ((arr[v + dy[i]][u + dx[i]] == '.')
						|| (arr[v + dy[i]][u + dx[i]] == 'T'))) {
			if ((visit[v + dy[i]][u + dx[i]].first == 0
					|| visit[v + dy[i]][u + dx[i]].second < turn)
					&& turn >= 0) {
				int direction = 0;
				if (i == 0)
					direction = 6;
				else if (i == 1)
					direction = 4;
				else if (i == 2)
					direction = 8;
				else if (i == 3)
					direction = 2;
				if (direction != d && d != 5)
					turn--;
				if (arr[v + dy[i]][u + dx[i]] == 'T' && turn >= 0
						&& result == "NO") {
					result = "YES";
				}
				dfs(v + dy[i], u + dx[i], direction);
				if (direction != d) {
					turn++;
					//visit[v][u].first = 0;
				}

			} else if (turn < 0)
				visit[v][u].first = 0;
			if (d == 5 && result == "NO") {
				visit.clear();
				visit.resize(m + 1, vector<pair<int, int>>(n + 1));
				visit[v][u].first = d;
				turn = 2;
			}

		}
	}

}
int main() {
	fast();
	int a = -1, b = -1;
	cin >> m >> n;
	arr.resize(m + 1, vector<char>(n + 1));
	visit.resize(m + 1, vector<pair<int, int>>(n + 1));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				a = i;
				b = j;
			}
		}
	}
	dfs(a, b, 5);
	cout << result << endl;
	return 0;
}