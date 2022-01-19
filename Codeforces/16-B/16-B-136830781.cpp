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

int main() {
	fast();
	int n, m, a, b, sum = 0;
	map<int, int> mp;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (mp.find(b) == mp.end())
			mp[b] = a;
		else
			mp[b] += a;
	}
	for (auto k =mp.rbegin(); k!=mp.rend();k++ ) {
		if (n >= k->second)
			sum += (k->second) * k->first;
		else
			sum += (k->first) * n;
		n -= k->second;
		if (n < 1)
			break;
	}

	cout << sum << endl;
	return 0;
}