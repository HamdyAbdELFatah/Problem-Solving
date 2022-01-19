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
	int n, x = -1, f = 0, t;
	cin >> n;
	while (n--) {
		cin >> t;
		while (true) {
			if (t % 2 == 0)
				t /= 2;
			else if (t % 3 == 0)
				t /= 3;
			else {
				if (t == x || x == -1)
					x = t;
				else
					f = 1;
				break;
			}
		}
	}

	if (f == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}