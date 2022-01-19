//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FastIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
void fast() {
	FastIO;
}
int main() {
	fast();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0)
			cout << "I hate ";
		else
			cout << "I love ";
		if (i == n - 1)
			cout << "it\n";
		else
			cout << "that ";
	}
	return 0;
}