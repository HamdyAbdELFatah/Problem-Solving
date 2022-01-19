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
    int n,m;
    string name,ip;
    cin>>n>>m;
    map<string,string> map;
    for(int i=0;i<n;i++){
        cin>>name>>ip;
        map[ip+";"]=name;
    }
    for(int i=0;i<m;i++){
        cin>>name>>ip;
        cout<<name<<" "<<ip<<" #"<<map[ip]<<endl;
    }
    return 0;
}