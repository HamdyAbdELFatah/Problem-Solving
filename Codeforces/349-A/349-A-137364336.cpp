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
	int n, c25 = 0, c50 = 0;
	string result = "YES";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 25)
			c25 ++;
		else if (arr[i] > 50) {
			if (c25 > 0 && c50 > 0) {
				c25--;
				c50--;
			} else if (c25 >= 3) {
				c25 -= 3;
			} else {
				result = "NO";
				break;
			}
		} else if (arr[i] > 25) {
			if (c25 > 0) {
				c25--;
				c50++;
			} else {
				result = "NO";
				break;
			}
		} else {
			result = "NO";
			break;
		}
	}
	cout << result << endl;

	return 0;
}