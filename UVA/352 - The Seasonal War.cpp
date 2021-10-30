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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
void read_each_digit(string s, vector<int> &v) {
	for (int i = 0; i < s.length(); ++i) {
		int x = s[i];
		v.push_back(x - 48);
	}
}
bool valid(int x, int y, int n) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

int main() {
	fast();
	int n, num = 1;
	while (cin >> n) {
		int c = 0;
		string s;
		vector<int> arr[n];
		int visit[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				visit[i][j]=0;
			}
		}
		for (int i = 0; i < n; ++i) {
			cin >> s;
			vector<int> v;
			read_each_digit(s, v);
			arr[i] = v;
		}
		queue<pair<int, int>> q;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visit[i][j] == 0 && arr[i][j] == 1) {
					c++;
					visit[i][j] = 1;
					q.push( { i, j });
					while (!q.empty()) {
						pair<int, int> u = q.front();
						q.pop();
						for (int i = 0; i < 8; ++i) {
							int x = u.first;
							int y = u.second;
							if (valid(x + dx[i], y + dy[i], n)
									&& visit[x + dx[i]][ y + dy[i]] == 0
									&& arr[x + dx[i]][ y + dy[i]] == 1) {
								visit[x + dx[i]][ y + dy[i]] = 1;
								q.push( { x + dx[i],  y + dy[i] });
							}
						}
					}
				}
			}
		}
		cout << "Image number " << num << " contains " << c << " war eagles."
				<< endl;
		num++;
	}
	return 0;
}