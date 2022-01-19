//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	FIO;
	int n, m, a, b;
	cin>>n>>m>>a>>b;
	cout<<min(n*a,n/m*b + min(n % m * a, b))<<endl;
	return 0;
}