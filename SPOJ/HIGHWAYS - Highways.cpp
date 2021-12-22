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
struct Node {
	int distenation, weight;
};
int main() {
	fast();
	int t, inf = 1000000005;
	cin >> t;
	while (t--) {
		int n, m, s, e, u, v, w;
		cin >> n >> m >> s >> e;
		multiset<pair<int, int>> q;
		vector<vector<Node>> arr(n + 1);
		int visit[n + 1];
		for (int i = 0; i <= n; ++i) {
			visit[i] = inf;
		}
		for (int i = 0; i < m; ++i) {
			cin >> u >> v >> w;
			arr[u].push_back( { v, w });
			arr[v].push_back( { u, w });
		}
		q.insert( { 0, s });
		visit[s] = 0;
		while (!q.empty()) {
			pair<int, int> city = *(q.begin());
			q.erase(q.begin());
			int u = city.second, uTime = city.first;

			for (size_t i = 0; i < arr[u].size(); ++i) {
				Node v = arr[city.second][i];
				if (uTime + v.weight < visit[v.distenation]) {
					visit[v.distenation] = uTime + v.weight;
					q.insert( { visit[v.distenation], v.distenation });

				}
			}
		}
		if (visit[e] == inf)
			cout << "NONE" << endl;
		else
			cout << visit[e] << endl;

	}

	return 0;
}