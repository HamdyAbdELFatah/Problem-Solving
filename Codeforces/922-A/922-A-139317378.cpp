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
	int x, y, copy = 0;
	cin >> x >> y;
	copy = y - 1;
	if ((y > 0)
			&& ((x == 0 && y == 0) || (x == copy)
					|| (x % 2 == 0 && copy % 2 == 0 && x > copy && copy > 0)
					|| (x % 2 != 0 && copy % 2 != 0 && x > copy && copy > 0)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}