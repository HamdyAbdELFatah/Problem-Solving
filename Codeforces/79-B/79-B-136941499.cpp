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
struct hash_pair {
	template<class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const {
		auto hash1 = hash<T1> { }(p.first);
		auto hash2 = hash<T2> { }(p.second);
		return hash1 ^ hash2;
	}
};
int main() {
	fast();
	string temp[] = { "Carrots", "Kiwis", "Grapes" };
	int n, m, k, t, a, b;
	cin >> n >> m >> k >> t;
	vector<pair<int, int>> v;
	unordered_map<pair<int, int>, int, hash_pair> mp;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		v.push_back( { a, b });
		mp[ { a, b }] = 0;
	}
	sort(v.begin(), v.end());
	for (int i = k; i > 0; --i) {
		mp[v[i - 1]] = i;
	}

	while (t--) {
		cin >> a >> b;
		string result = "o";
		if (mp.find( { a, b }) != mp.end())
			result = "Waste";
		else
			for (int i = k - 1; i >= 0; --i) {
				if (a > v[i].first) {
					result = temp[((((a - 1) * m) + (b - i-1 ))-1) % 3];
					break;
				} else if (a == v[i].first) {
					if (b > v[i].second) {
						result = temp[((((a - 1) * m) + (b - i -1))-1) % 3];
						break;
					} else
						continue;
				}
			}
		if (result == "o") {
			result = temp[(((a - 1) * m) + b-1 ) % 3];
		}
		cout << result << endl;
	}

	return 0;
}