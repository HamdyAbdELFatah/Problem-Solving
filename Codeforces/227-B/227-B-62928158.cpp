#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t;
    unsigned long long s1=0,s2=0;
    scanf("%d",&n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
       cin>>m;
       mp[m] =i;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&t);
       s1+=mp[t]-0+1;
       s2+=n-mp[t];
    }
    cout<<s1<<" "<<s2<<endl;
    return 0;
}