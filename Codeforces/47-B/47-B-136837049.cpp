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
	int arr[3] = { -1, -1, -1 };
	string s;
	for (int i = 0; i < 3; ++i) {
		cin >> s;
		if (s[1] == '>') {
			if (arr[s[0] - 65] == -1)
				arr[s[0] - 65] = s[2] - 65;
			else
				arr[s[0] - 65] = 100;

		} else {
			if (arr[s[2] - 65] == -1)
				arr[s[2] - 65] = s[0] - 65;
			else
				arr[s[2] - 65] = 100;
		}

	}
	int c = 0;
	for (int i = 0; i < 3; ++i) {
		if (arr[i] == -1) {
			s[0] = char('A' + i);
			c++;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (arr[i] != -1 && arr[i] != 100) {
			s[1] = char('A' + i);
			c++;
			break;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (arr[i] == 100) {
			s[2] = char('A' + i);
			c++;
		}
	}
	if (c == 3)
		cout << s << endl;
	else
		cout << "Impossible" << endl;

	return 0;
}