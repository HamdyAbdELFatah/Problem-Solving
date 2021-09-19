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
	int start, end;
};
int visit[101];
vector<vector<int>> arr;
void dfs(int v, int n) {
	visit[v] = 1;
	for (int i = 1; i <= n; ++i) {
		if (arr[v][i] == 1 && visit[i] == 0) {
			dfs(i, n);
		}
	}
}
int main() {
	fast();
	int n, c = 0;
	cin >> n;
	arr.resize(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (visit[i] == 0) {
			dfs(i, n);
			c++;
		}
	}

	cout << c << endl;

	return 0;
}

