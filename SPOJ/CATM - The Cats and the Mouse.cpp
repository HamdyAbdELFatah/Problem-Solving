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
struct animal {
	int x, y, type;
};
bool valid(int x, int y, int n, int m) {
	if (x > 0 && x <= n && y > 0 && y <= m)
		return true;
	return false;
}

int main() {
	fast();
	int n, m, t;
	cin >> n >> m >> t;
	while (t--) {
		int arr[n + 1][m + 1] = { 0 };
		int fx, fy, cx1, cy1, cx2, cy2;
		cin >> fx >> fy >> cx1 >> cy1 >> cx2 >> cy2;
		queue<animal> q;
		q.push( { fx, fy, 1 });
		q.push( { cx1, cy1, 2 });
		q.push( { cx2, cy2, 2 });
		arr[fx][fy] = 1;
		arr[cx1][cy1] = 2;
		arr[cx2][cy2] = 2;
		bool stop = true;
		while (!q.empty() && stop) {
			animal p = q.front();
			q.pop();
			if (p.type != arr[p.x][p.y])
				continue;
			for (int i = 0; i < 4; ++i) {
				if (p.type == 2) {
					if (valid(p.x + dx[i], p.y + dy[i], n, m)
							&& arr[p.x + dx[i]][p.y + dy[i]] <= 1) {
						arr[p.x + dx[i]][p.y + dy[i]] = 2;
						q.push( { p.x + dx[i], p.y + dy[i], 2 });
					}
				} else {
					if (valid(p.x + dx[i], p.y + dy[i], n, m)
							&& arr[p.x + dx[i]][p.y + dy[i]] == 0) {
						arr[p.x + dx[i]][p.y + dy[i]] = 1;
						q.push( { p.x + dx[i], p.y + dy[i], 1 });
					} else if (!valid(p.x + dx[i], p.y + dy[i], n, m)) {
						stop = false;
						break;
					}
				}

			}
		}

		if (stop)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}