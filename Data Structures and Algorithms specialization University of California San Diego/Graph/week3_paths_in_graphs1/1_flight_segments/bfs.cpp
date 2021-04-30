#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
using namespace std;
int main()
{
    FIO
    int n,m,u,v;
    cin>>n>>m;
    int dist[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=n+1;
    }
    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    cin>>u>>v;
    queue<int> q;
    q.push(u);
    dist[u]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0;i<arr[u].size();i++){
            if(dist[arr[u][i]]==n+1){
                q.push(arr[u][i]);
                dist[arr[u][i]]=dist[u]+1;
            }
        }
    }
    if(dist[v]!=n+1)
        cout<<dist[v]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
