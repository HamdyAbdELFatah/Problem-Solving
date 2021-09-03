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
	string a, b;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	int n = a.length(), m = b.length();
	vector<vector<int>> v(n, vector<int>(m, 0));
	vector<vector<char>> c(n, vector<char>(m, ' '));
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i] == b[j]) {
				v[i][j] = v[i - 1][j - 1] + 1;
				c[i][j] = '\\';
			} else if (v[i][j - 1] > v[i - 1][j]) {
				v[i][j] = v[i][j - 1];
				c[i][j] = '<';
			} else {
				v[i][j] = v[i - 1][j];
				c[i][j] = '^';
			}
		}
	}
	stack<char> s;
	int i = n - 1, j = m - 1;
	while (i != 0 && j != 0) {
		if (c[i][j] == '^')
			i--;
		else if (c[i][j] == '<')
			j--;
		else {
			s.push(a[i]);
			i--;
			j--;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}

