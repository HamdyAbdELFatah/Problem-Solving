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
	int t, n, m,x,y;
	cin>>t;
	string path ="IEHOVA#";
	while(t--){
		cin>>m>>n;
		char c[m][n];
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin>>c[i][j];
				if(c[i][j]=='@'){
					x=i;
					y=j;
				}
			}

		}
		for (int i = 0; i < 7; ++i) {
			if(y>0){
				if(c[x][y-1]==path[i]){
					if(path[i]!='#')
						cout<<"left ";
					else
						cout<<"left";
					y--;
					continue;
				}
			}
			if(y<n-1){
				if(c[x][y+1]==path[i]){
					if(path[i]!='#')
						cout<<"right ";
					else
						cout<<"right";
					y++;
					continue;
				}
			}
			if(x>0){
				if(c[x-1][y]==path[i]){
					if(path[i]!='#')
						cout<<"forth ";
					else
						cout<<"forth";
					x--;
					continue;
				}
			}
		}
		cout<<endl;
	}

	return 0;
}
