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
	int n;
	cin >> n;
	int arr[n], sortedArr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sortedArr[i] = arr[i];
	}
	sort(arr, arr + n);
	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] != sortedArr[i])
			c++;
	}
	if(c>2)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}