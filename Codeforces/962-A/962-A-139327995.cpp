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
	int n, sum = 0, sum2 = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; ++i) {
		sum2 += arr[i];
		if (sum2 >= (sum + 1) / 2) {
			cout << (i + 1) << endl;
			break;
		}
	}

	return 0;
}