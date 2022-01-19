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

string s, u = "";
stack<char> t;
priority_queue<char, vector<char>, greater<char>> q;
int c = 1;

void popSmallest() {
	while (!t.empty() && q.top() >= t.top()) {
		u += t.top();
		t.pop();
	}
}

int main() {
	fast();
	cin >> s;
	int arr[27] = { 0 };

	for (int i = 0; i < s.length(); ++i) {
		q.push(s[i]);
		arr[s[i] - 97]++;
	}

	for (int i = 0; i < s.length(); ++i) {
		if (q.top() == s[i]) {
			u += s[i];
			arr[s[i] - 97]--;
			q.pop();

			while (!t.empty() && t.top() == s[i]) {
				u += s[i];
				t.pop();
			}
			popSmallest();

		} else if (arr[q.top() - 97] == 0) {
			popSmallest();
			q.pop();
			i--;
			popSmallest();

		} else {
			popSmallest();
			t.push(s[i]);
			arr[s[i] - 97]--;
			popSmallest();

		}

	}

	while (!t.empty()) {
		u += t.top();
		t.pop();
	}

	cout << u << endl;
	return 0;
}