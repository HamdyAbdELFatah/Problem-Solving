//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int fr[100001];
int main() {
	FIO;
	int n,x,c=0,m=0;
	cin>>n;
	n*=2;
	while(n--){
		cin>>x;
		if(!fr[x]){
			fr[x]=1;
			c++;
		}else{
			c--;
		}
		m=max(m,c);
	}
	cout<<m<<endl;
	return 0;
}