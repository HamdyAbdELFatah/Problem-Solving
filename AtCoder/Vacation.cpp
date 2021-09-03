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
int n;
int memo[1000005][3];
int dp(int last, int index, vector<int> arr[]) {
	if (index >= n)
		return 0;
	int result = 0;
	vector<int> v;
	for (int i = 0; i < 3; ++i) {
		if (i == last)
			continue;
		if(memo[index][i]){
			v.push_back(memo[index][i]);
			continue;
		}
		v.push_back(dp(i, index + 1, arr) + arr[index][i]);
		memo[index][i]= v.back();
	}
	if(index!=0)
		result = max(v[0], v[1]);
	else
		result = max(v[0], max(v[1], v[2]));
	return result;
}
int main() {
	FIO;
	int x;
	cin >> n;
	vector<int> arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> x;
		arr[i].push_back(x);
		cin >> x;
		arr[i].push_back(x);
		cin >> x;
		arr[i].push_back(x);
	}
	cout << dp(-1, 0, arr) << endl;

	return 0;
}
