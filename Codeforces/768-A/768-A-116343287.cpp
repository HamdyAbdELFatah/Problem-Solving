//============================================================================
// Author      : Hamdy Abd El Fattah $
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	FIO;
	int n;
	cin>>n;
	int arr[n];
	int _max=-1,
	_min = INF, c = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		_max = max(_max, arr[i]);
		_min = min(_min, arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] > _min && arr[i] < _max)
			c++;
	}
	cout << c;
	return 0;
}