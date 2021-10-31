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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
bool valid(int x, int y, int n) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

int main() {
	fast();
	int t;
	cin >> t;
	while (t--) {
		char arr[3][3];
		int cx = 0, co = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == 'X')
					cx++;
				else if (arr[i][j] == 'O')
					co++;
			}
		}
		int x = 0, o = 0;
		for (int i = 0; i < 3; ++i) {
			int ca = 0, cb = 0;
			for (int j = 0; j < 3; ++j) {
				if (arr[i][j] == 'X')
					ca++;
				else if (arr[i][j] == 'O')
					cb++;

			}
			if (ca == 3)
				x++;
			else if (cb == 3)
				o++;
		}
		for (int i = 0; i < 3; ++i) {
			int ca = 0, cb = 0;

			for (int j = 0; j < 3; ++j) {
				if (arr[j][i] == 'X')
					ca++;
				else if (arr[j][i] == 'O')
					cb++;
			}
			if (ca == 3)
				x++;
			else if (cb == 3)
				o++;
		}
		int ca = 0, cb = 0;
		for (int i = 0; i < 3; ++i) {
			if (arr[i][i] == 'X')
				ca++;
			else if (arr[i][i] == 'O')
				cb++;
		}
		if (ca == 3)
			x++;
		else if (cb == 3)
			o++;
		ca = 0, cb = 0;
		for (int i = 2; i >= 0; --i) {
			if (arr[2 - i][i] == 'X')
				ca++;
			else if (arr[2 - i][i] == 'O')
				cb++;
		}
		if (ca == 3)
			x++;
		else if (cb == 3)
			o++;

		if ((o == 1 && x == 0 && cx == co)
				|| ((x == 1 || x == 2) && o == 0 && cx - co == 1))
			cout << "yes" << endl;
		else if (x == 0 && o == 0 && (cx == co || cx - co == 1))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}