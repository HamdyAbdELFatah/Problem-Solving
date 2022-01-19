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
	int n,sum=0;
	for (int i = 0; i < 5; ++i) {
		cin>>n;
		sum+=n;
	}
	if(sum%5==0&&sum>0)
		cout<<sum/5<<endl;
	else
		cout<<-1<<endl;

	return 0;
}