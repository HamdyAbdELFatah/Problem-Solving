#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	FIO;
	ll n,p=0;
	cin>>n;
	for (int j = 2; j <= n; ++j) {
		int c=0;
		int x=j;
		for (int i = 2; x>1 ; ++i) {
			if(x%i==0){
				c++;
			}
			while(x%i==0){
				x/=i;
			}
		}
		if(c==2)
			p++;
	}
	cout<<p<<endl;
	return 0;
}