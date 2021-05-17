//============================================================================
// Author      : Hamdy Abd El Fattah $
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int parent[201];
struct Edge{
	int u,v;
	double w;
	Edge(int u = 0, int v = 0, double w = 0): u(u), v(v), w(w){}
    bool operator<(const Edge& a) const
    {
        return w < a.w;
    }
};
struct Point{
	double x,y;
	Point(int x = 0, int y = 0): x(x), y(y){}
};
double distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
int find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}
void union_set(int u, int v) {
  parent[u] = parent[v];
}

int main() {
	FIO;
	int n, u, v;
	double x,y;
	cin >> n;
	vector<Edge> edges;
	vector<Point> points;
	for (int i = 0; i < n; i++) {
		parent[i]=i;
		cin>>x>>y;
		for (int j = points.size()-1; j >= 0; j--) {
			edges.push_back(Edge(i,j,distance(x, y, points[j].x, points[j].y)));
		}
		points.push_back(Point(x,y));
	}
	sort(edges.begin(),edges.end());
	int pointer=0;
	double total=0;
	vector<Edge> result;
	for(int i=0;i<edges.size();i++){
		u=find_set(edges[pointer].u);
		v=find_set(edges[pointer].v);
		if(u != v){
			result.push_back(edges[pointer]);
		    union_set(u, v);
		}
		pointer++;

	}
	for (int i = 0; i < result.size(); ++i) {
		total+=result[i].w;

	}
	cout << std::fixed << std::setprecision(9) << total<<endl;
	return 0;
}

