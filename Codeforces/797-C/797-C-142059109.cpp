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
	string s, u = "";
	stack<char> t;
	cin >> s;
	priority_queue<char, vector<char>, greater<char>> q;
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
			int c = 1;
			while (c) {
				c = 0;
				while (!t.empty() && t.top() == s[i]) {
					u += s[i];
					t.pop();
					c++;
				}
				while (!t.empty() && q.top() >= t.top()) {
					u += t.top();
					t.pop();
					c++;
				}
			}
 
		} else if (arr[q.top() - 97] == 0) {
			while (!t.empty() && q.top() >= t.top()) {
				u += t.top();
				t.pop();
			}
			q.pop();
			i--;
			while (!t.empty() && q.top() >= t.top()) {
				u += t.top();
				t.pop();
			}
		} else {
			while (!t.empty() && q.top() >= t.top()) {
				u += t.top();
				t.pop();
			}
			t.push(s[i]);
			arr[s[i] - 97]--;
 
			while (!t.empty() && q.top() >= t.top()) {
				u += t.top();
				t.pop();
			}
		}
 
	}
 
	while (!t.empty()) {
		u += t.top();
		t.pop();
	}
 
	cout << u << endl;
	return 0;
}