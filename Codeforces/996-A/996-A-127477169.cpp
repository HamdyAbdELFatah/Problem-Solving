//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
int main() {
	FIO;
	int n , c=0;
	cin >> n;
	if(n>=100){
		c+=n/100;
		n%=100;
	}
	if(n>=20){
		c+=n/20;
		n%=20;
	}
	if(n>=10){
		c+=n/10;
		n%=10;
	}
	if(n>=5){
		c+=n/5;
		n%=5;
	}
	if(n>=1){
		c+=n/1;
		n%=1;
	}
	cout<<c<<endl;



	return 0;
}