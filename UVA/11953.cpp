//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
bool valid(int i ,int j,int n){
	return i>=0 && j>=0 && i<n && j<n;
}
vector<string> c;
int dx[4] = {0, 0,1,-1};
int dy[4] = {1,-1,0, 0};
void dfs(int i,int j,int n){
	for (int k = 0; k < 4; ++k) {
		int x=i+dx[k];
		int y=j+dy[k];
		if(valid(x,y,n)){
			if(c[x][y]!='.'){
				c[x][y]='.';
				dfs(x,y,n);
			}
		}
	}
}
int main() {
	FIO;
	int t, n, count=0;
	cin>>t;
	for(int s=1;s<=t;s++){
		cin>>n;
		string x;
		for (int i = 0; i < n; ++i) {
			cin>>x;
			c.push_back(x);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if(c[i][j]=='x'){
					count++;
					c[i][j]='.';
					dfs(i,j,n);
				}
			}

		}
		c.clear();
		cout<<"Case "<<s<<": "<<count<<endl;
		count =0;
	}

	return 0;
}