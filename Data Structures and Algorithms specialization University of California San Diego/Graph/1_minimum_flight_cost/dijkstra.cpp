//============================================================================
// Author      : Hamdy Abd El Fattah $
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int main() {
	FIO
	int n, m, u, v, w;
	cin >> n >> m;
	int dist[n + 1];
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}
	vector<pair<int,int>> arr[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		arr[u].push_back({v,w});
	}
	cin >> u >> v;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,u});
	dist[u] = 0;
	while (!q.empty()) {
		u=q.top().second;
		q.pop();
		for (int i = 0; i < arr[u].size(); i++){
			if (dist[arr[u][i].first] > dist[u] + arr[u][i].second) {
				dist[arr[u][i].first] = dist[u] + arr[u][i].second;
				q.push({dist[arr[u][i].first] ,arr[u][i].first});
			}
		}
	}
	if(dist[v] != INF){
		cout << dist[v] << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}

