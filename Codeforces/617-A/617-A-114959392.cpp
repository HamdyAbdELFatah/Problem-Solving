#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int main() {
	FIO
	int n;
	cin >> n;
	if(n%5)
		cout<<n/5+1<<endl;
	else
		cout<<n/5<<endl;
	return 0;
}