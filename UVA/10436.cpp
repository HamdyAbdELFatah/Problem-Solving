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
	int index, cost;
};
int main() {
	fast();
	int t, inf = 100000, count = 1;
	cin >> t;
	while (t--) {
		int numStation, numPath, cost;
		string u, v;
		cin >> numStation;
		int adj[numStation][numStation];
		int next[numStation][numStation];
		for (int i = 0; i < numStation; ++i) {
			for (int j = 0; j < numStation; ++j) {
				if (i == j) {
					adj[i][j] = 0;
					next[i][j] = -1;
					continue;
				}
				adj[i][j] = inf;
				next[i][j] = -1;
			}
		}
		unordered_map<string, Node> nodes;
		string index[numStation];
		for (int i = 0; i < numStation; ++i) {
			cin >> u >> cost;
			nodes[u] = { i, cost };
			index[i] = u;
		}

		cin >> numPath;
		for (int i = 0; i < numPath; ++i) {
			cin >> u >> v >> cost;
			adj[nodes[u].index][nodes[v].index] = cost;
			adj[nodes[v].index][nodes[u].index] = cost;
			next[nodes[u].index][nodes[v].index] = nodes[v].index;
			next[nodes[v].index][nodes[u].index] = nodes[u].index;
		}

		for (int k = 0; k < numStation; ++k) {
			for (int i = 0; i < numStation; ++i) {
				for (int j = 0; j < numStation; ++j) {
					if (adj[i][k] == inf || adj[k][j] == inf)
						continue;
					if (adj[i][j] > adj[i][k] + adj[k][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						next[i][j] = next[i][k];
					}
				}
			}
		}

		cin >> numStation;
		if (count > 1)
			cout << endl;
		cout << "Map #" << count << endl;
		for (int i = 0; i < numStation; ++i) {
			cout << "Query #" << (i + 1) << endl;
			cin >> u >> v >> cost;
			double d = adj[nodes[u].index][nodes[v].index] * 2;
			int son = nodes[u].index;
			vector<int> path = { son };
			d += nodes[index[son]].cost;
			while (next[nodes[u].index][nodes[v].index] != -1) {
				son = next[son][nodes[v].index];
				path.push_back(son);
				d += nodes[index[son]].cost;
				if (son == nodes[v].index) {
					break;
				}
			}
			for (int i = 0; i < path.size(); ++i) {
				cout << index[path[i]];
				if (i < path.size() - 1)
					cout << " ";
			}
			d += (d * 0.1);
			d = d / cost;
			cout << "\nEach passenger has to pay : ";
			cout << fixed << setprecision(2) << d << " taka" << endl;
		}
		count++;
	}
	return 0;
}