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
	cin >> n;
	vector<int> arr[n + 1];
	int visit[n + 1] = { -1 };
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		visit[i] = -1;
		cin >> m;
		if (m == -1) {
			q.push(i);
			visit[i] = 0;
		} else
			arr[m].push_back(i);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < arr[u].size(); ++i) {
			int v = arr[u][i];
			if (visit[v] == -1) {
				visit[v] = visit[u] + 1;
				q.push(v);
				mx = max(visit[v], mx);
			}
		}
	}

	cout << mx + 1 << endl;
	return 0;
}