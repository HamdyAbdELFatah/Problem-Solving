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
struct Node {
	int start, end;
};
int visit[10001], cycle = 0, c = 1;
int parent[10001];
vector<vector<int>> v(10001);

void dfs(int d) {
	visit[d] = 1;
	for (int i = 0; i < v[d].size(); ++i) {
		if (visit[v[d][i]] == 0) {
			c++;
			parent[v[d][i]]=d;
			dfs(v[d][i]);
		} else if (v[d][i] != parent[d]) {
			cycle = 1;
		}
	}
}
int main() {
	fast();
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		if (x == y)
			cycle = 1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);

	if (c < n || cycle == 1)
		cout << "NO\n";
	else
		cout << "YES\n";

	return 0;
}

