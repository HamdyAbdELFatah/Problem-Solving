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
    int color[n+1]={0};
    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    queue<int> q;
    int result=1;
    for(int j=1;j<=n;j++){
        if(color[j]!=0)
            continue;
            q.push(j);
            color[j]=1;
        while(!q.empty()){
            u=q.front();
            q.pop();
            for(int i=0;i<arr[u].size();i++){
                if(color[arr[u][i]]==0){
                    q.push(arr[u][i]);
                    color[arr[u][i]]=color[u]==1?2:1;
                }
                if(color[u]==color[arr[u][i]]){
                    result=0;
                }
            }
        }
    }
    cout<<result<<endl;
    return 0;
}
