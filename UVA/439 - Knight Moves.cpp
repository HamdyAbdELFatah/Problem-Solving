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

int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

bool valid(int x, int y, int n, int m) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int main() {
	fast();
	string s;
	while (cin >> s) {
		string start = s;
		int visit[8][8];
		pair<int, int> source, distination;
		queue<pair<int, int>> q;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				visit[i][j] = -1;
			}
		}
		source = make_pair(s[0] - 97, s[1] - 49);
		q.push(source);
		visit[source.first][source.second] = 0;
		cin >> s;
		distination = make_pair(s[0] - 97, s[1] - 49);
		bool stop = 1;
		while (!q.empty() && stop) {
			pair<int, int> u = q.front();
			q.pop();
			for (int i = 0; i < 8; ++i) {
				int x = u.first + dx[i], y = u.second + dy[i];
				if (valid(x, y, 8, 8) && visit[x][y] == -1) {
					visit[x][y] = visit[u.first][u.second] + 1;
					q.push( { x, y });
					pair<int, int> v = make_pair(x, y);
					if (distination.first == v.first
							&& distination.second == v.second) {
						stop = 0;

					}
				}
			}
		}
		cout << "To get from " << start << " to " << s << " takes "
				<< visit[distination.first][distination.second]
				<< " knight moves." << endl;
	}
	return 0;
}