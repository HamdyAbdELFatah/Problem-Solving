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
	int n;
	unordered_map<string, int> m;
	cin >> n;
	char x, y;
	cin >> x;
	for (int i = 1; i < n; ++i) {
		string key;
		key.push_back(x);
		cin >> y;
		key.push_back(y);
		m[key]++;
		x = y;
	}
	int mx = -1;
	string sMax = "";
	for (const auto &e : m) {
		if (e.second > mx){
			sMax = e.first;
			mx = e.second;
		}
	}
	cout << sMax << endl;
	return 0;
}