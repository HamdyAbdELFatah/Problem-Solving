//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;

int main() {
	FIO;
	int n,
	w;
	cin >> n >> w;
	vector<vector<ll>> value(n + 1, vector<ll>(w + 1));
	pair<int, int> arr[n + 1];
	arr[0].first = 0;
	arr[0].second = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].first;
		cin >> arr[i].second;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= w; ++j) {
			if (j >= arr[i].first) {
				if (j - arr[i].first > 0) {
					value[i][j] = value[i - 1][j - arr[i].first];
				} else
					value[i][j] = 0;
				value[i][j] = max(value[i - 1][j], arr[i].second + value[i][j]);
			} else {
				value[i][j] = value[i - 1][j];
			}

		}
	}

	cout << value[n][w] << endl;
	return 0;
}