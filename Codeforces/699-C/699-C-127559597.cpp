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
	last = 0, c = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0) {
			last = 0;
			c++;
		} else if (arr[i] == 1) {
			if (last == 2) {
				c++;
				last = 0;
			} else
				last = 2;
		} else if (arr[i] == 2) {
			if (last == 1) {
				c++;
				last = 0;
			} else
				last = 1;
		} else {
			if (last == 1)
				last = 2;
			else if (last == 2)
				last = 1;
			else
				last = 0;
		}
	}
	cout << c << endl;
	return 0;
}