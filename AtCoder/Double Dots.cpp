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
	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> arr(n + 1);
	vector<int> visit(n + 1, 0);
	queue<int> q;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	q.push(1);
	v = 0;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < arr[u].size(); ++i) {
			if (visit[arr[u][i]] == 0) {
				visit[arr[u][i]] = u;
				q.push(arr[u][i]);
			}
		}

	}

	cout << "Yes\n";
	for (int i = 2; i <= n; ++i) {
		cout << visit[i] << endl;

	}
	return 0;
}
