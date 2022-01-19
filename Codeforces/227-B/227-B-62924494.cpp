#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t;
    unsigned long long s1=0,s2=0;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
       cin>>m;
       mp[m] =i;
    }
    cin>>m;
    for(int i=0;i<m;i++){
       cin>>t;
       s1+=mp[t]-0+1;
       s2+=n-mp[t];
    }
    cout<<s1<<" "<<s2<<endl;
    return 0;
}