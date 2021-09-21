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
int visit[101];
queue<int> q;
int founded = 0;
void bfs(int f, vector<vector<int>> &arr) {
	if (founded == 1)
		return;
	int u = q.front();
	q.pop();
	for (int i = 1; i <= arr[u].size(); ++i) {
		if (arr[u][i] == 1 && visit[i] == 0) {
			q.push(i);
			visit[i] = visit[u] + 1;
			if (i == f) {
				founded = 1;
				return;
			}
		}
	}
	if (!q.empty())
		bfs(f, arr);
}
int main() {
	fast();
	int n, s, f;
	cin >> n >> s >> f;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}

	visit[s] = 1;
	q.push(s);
	bfs(f, arr);
	if (founded == 1)
		cout << visit[f] - 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
