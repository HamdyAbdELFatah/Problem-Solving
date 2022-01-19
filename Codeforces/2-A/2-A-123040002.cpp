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
	string name, max_name;
	int n, x = 0, score;
	unordered_map<string, int> um;
	unordered_map<string, int> um2;
	vector<pair<string, int>> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> name >> score;
		v.push_back( make_pair(name, score));
		if (um.count(name) == 0)
			um[name] = score;
		else {
			um[name] += score;
		}

	}
	for (int i = 0; i < v.size(); ++i) {
		if (um[v[i].first] > x) {
			x = um[v[i].first];
		}
	}
	for (int i = 0; i < n; ++i) {
		name = v[i].first, score = v[i].second;
		if (um2.count(name) == 0)
			um2[name] = score;
		else {
			um2[name] += score;
		}
		if (um2[name] >= x && um[name]==x ){
			max_name = name;
			break;
		}
	}
	cout << max_name << endl;
	return 0;
}