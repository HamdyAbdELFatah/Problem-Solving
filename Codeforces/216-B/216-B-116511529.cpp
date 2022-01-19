//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int teamA[101];
int teamB[101];
int visitA[101];
int visitB[101];
vector<int> arr[101];
void dfsA(int x){
	for (int i = 0; i < arr[x].size(); ++i) {
		if(visitA[arr[x][i]])
			continue;
		visitA[arr[x][i]]=1;
		if(!teamA[arr[x][i]]){
			int temp =1;
			for (int j = 0; j < arr[arr[x][i]].size(); ++j) {
				if(teamA[arr[arr[x][i]][j]])
					temp =0;
			}
			if(temp)
				teamA[arr[x][i]]=1;
		}
		dfsA(arr[x][i]);
	}
}
void dfsB(int x){
	for (int i = 0; i < arr[x].size(); ++i) {
		if(visitB[arr[x][i]])
			continue;
		visitB[arr[x][i]]=1;
		if(!teamB[arr[x][i]]&&!teamA[arr[x][i]]){
			int temp =1;
			for (int j = 0; j < arr[arr[x][i]].size(); ++j) {
				if(teamB[arr[arr[x][i]][j]])
					temp =0;
			}
			if(temp)
				teamB[arr[x][i]]=1;
		}
		dfsB(arr[x][i]);
	}
}
int main() {
	FIO;
	int n, m, u, v;
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if(visitA[i])
			continue;
		visitA[i]=1;
		teamA[i]=1;
		dfsA(i);
	}
	for (int i = 1; i <= n; ++i) {
		if(visitB[i])
			continue;
		visitB[i]=1;
		if(!teamA[i])
			teamB[i]=1;
		dfsB(i);

	}
	int c=0;
	for (int i = 1; i <= n; ++i) {
		if(teamA[i]||teamB[i]){
			c++;
		}
	}
	int z=n-c;
	if(c%2!=0)
		z++;
	cout<<z<<endl;
	return 0;
}