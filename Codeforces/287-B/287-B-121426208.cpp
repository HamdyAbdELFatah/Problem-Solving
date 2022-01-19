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
	ll n, k, l = 2, r = 0, m, sum, ans = -1;
	cin >> n >> k;
	r = k;
	m = l;
	if(n ==1)
		ans = 0;
	else if(k == n)
		ans = 1;
	else{
		while(l<=r){
			sum = (k - m + 1) * (m + k )/ 2 - (k - m);
			if(sum > n){
				l = m + 1;
				ans = k - m + 1;
			}else if (sum < n){
				if(l == 2 && r == k){
					ans = -1;
					break;
				}
				r = m - 1;
				m = (r + l) / 2 ;

			}else{
				ans = k - m + 1;
				break;
			}
			m = (r + l) / 2 ;


		}
	}
	cout << ans <<endl;
	return 0;
}