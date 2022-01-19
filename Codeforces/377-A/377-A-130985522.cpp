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
	int n, m, k, p = 0;
	cin >> n >> m >> k;
	vector<vector<char>> arr(n, vector<char>(m));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == '.') {
				if (p == 0) {
					q.push( { i, j });
					arr[i][j] = '+';
				}
				p++;
			}

		}
	}
	p = p - k - 1;
	while (!q.empty()) {
		auto point = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (p > 0 && valid(point.first + dx[i], point.second + dy[i], n, m)
					&& arr[point.first + dx[i]][point.second + dy[i]] == '.') {
				arr[point.first + dx[i]][point.second + dy[i]] = '+';
				q.push( { point.first + dx[i], point.second + dy[i] });
				p--;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '+')
				cout << ".";
			else if (arr[i][j] == '.')
				cout << "X";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}