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
float distance(int x, int y)
{
    return sqrt(pow(x - 0, 2) +
                pow(y - 0, 2) * 1.0);
}

int main() {
	FIO;
	int r,d,n,x,y,pr,c=0;
	float pd;
	cin>>r>>d>>n;
	int i=1;
	while(n--){
		cin>>x>>y>>pr;
		pd=distance(x, y) ;
		//cout<<"X: "<<x<<" ,Y: "<<y<<" >> "<<pd<<"  r:"<<pr<<endl;
		if(r-d<=pd-pr &&pd+pr<=r){
			c++;
			//cout<<i<<endl;
		}
		i++;
	}
	cout<<c<<endl;
	return 0;
}