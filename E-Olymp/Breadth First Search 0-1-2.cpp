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
	if (x > 0 && x <= n && y > 0 && y <= m)
		return true;
	return false;
}
struct Node {
	int v, w;
};
int main() {
	fast();
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	vector<Node> arr[n + 1];
	int dist[n + 1];
	for (int i = 0; i <= n; ++i) {
		dist[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		int w, u, v;
		cin >> u >> v >> w;
		arr[u].push_back( { v, w });
		arr[v].push_back( { u, w });
	}
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < arr[u].size(); ++i) {
			if (dist[arr[u][i].v] == -1 || (dist[arr[u][i].v] > dist[u] + 1)|| (dist[arr[u][i].v] > dist[u] + 2)
					|| (dist[arr[u][i].v] > dist[u] && arr[u][i].w == 0)) {
				dist[arr[u][i].v] = dist[u] + arr[u][i].w;
				q.push(arr[u][i].v);
			}
		}
	}
	cout << dist[d] << endl;
	return 0;
}