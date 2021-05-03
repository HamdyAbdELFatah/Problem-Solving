//============================================================================
// Author      : Hamdy Abd El Fattah $
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
struct Node{
	int u,v,w;
	Node(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w){}
};

int main() {
	FIO;
	int n, m, u, v, w;
	cin >> n >> m;
	int dist[n + 1];
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	vector<Node> arr(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		arr.push_back(Node(u,v,w));
	}

	dist[1] = 0;
	int c=0;
	while (n--) {
		if(n==1)
			c=0;
		for (int i = 0; i < arr.size(); i++){
			if (dist[arr[i].v] > dist[arr[i].u] + arr[i].w) {
				dist[arr[i].v] = dist[arr[i].u] + arr[i].w;
				c++;
			}
		}
	}
	if(c){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}
	return 0;
}

