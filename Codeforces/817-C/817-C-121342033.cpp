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
	ll n, c = INFL, s = 0 ,l = 1, r = 0, m;
	cin >> n >> s;
	m = n;
	r = m;
	while(l < r){
		string x = to_string(m);
		ll sum = 0;
		for (int i = 0; i < x.length(); ++i) {
			sum += (x[i]-'0');
		}
		if(m - sum >= s){
			r = m;
			c = min(m,c);
		}else{
			l = m+1;
		}
		m = ( l + r ) / 2 ;
	}
	if(c != INFL)
		cout<< n - c + 1<<endl;
	else
		cout<<0<<endl;
	return 0;
}