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
int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	fast();
	int n, x0, y0, x1, y1, m, u, v;
	cin >> x0 >> y0 >> x1 >> y1 >> n;
	unordered_map<int, vector<pair<int, int>>> arr;
	map<pair<int, int>, int> visit;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		cin >> m >> u >> v;
		if (arr.count(m)) {
			arr[m].push_back( { u, v });
		} else {
			vector<pair<int, int>> temp;
			temp.push_back( { u, v });
			arr[m] = temp;
		}
	}

	q.push(make_pair(x0, y0));
	visit[ { x0, y0 }] = 0;
	int stop = 1;
	while (!q.empty() && stop) {
		pair<int, int> e = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i) {
			pair<int, int> p = make_pair(e.first + dx[i], e.second + dy[i]);
			if (visit[p] == 0 && arr.count(p.first)) {
				for (int j = 0; j < arr[p.first].size(); j++) {
					if (arr[p.first].at(j).first <= p.second
							&& arr[p.first].at(j).second >= p.second) {
						visit[p] = visit[e] + 1;
						q.push(p);
						if (p == make_pair(x1, y1)) {
							stop = 0;
						}
						break;
					}
				}
			}
		}

	}
	if (visit.count( { x1, y1 }))
		cout << visit[ { x1, y1 }] << endl;
	else
		cout << -1 << endl;

	return 0;
}