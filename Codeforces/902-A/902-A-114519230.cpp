#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
using namespace std;
int main()
{
    FIO
    int n,m,max=0,f=1;
    cin>>n>>m;
    string result="NO\n";
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a>max){
           f=0;
        }
        if(b>max){
            max=b;
        }
        if(f&&m<=b){
           result="YES\n";
        }
    }
    cout<<result;
    return 0;
}