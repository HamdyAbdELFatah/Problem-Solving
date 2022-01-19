#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
using namespace std;
int main()
{
    FIO
    ll n,sum=0,x=0,y=1;
    cin>>n;
    vector<int> v;
    map<int,int> m;
    if(n>2)
    {
        int i=0;
        while(sum<=n)
        {
            v.push_back(sum);
            m[sum]=i;
            sum=x+y;
            x=y;
            y=sum;
            i++;
        }
        int index =m[n];
        cout<<"0 "<<v[index-1]<<" "<<v[index-2]<<"\n";
    }
    else
    {
        if(n==1)
            cout<<"0 0 1\n";
        else if(n==2)
            cout<<"0 1 1\n";
        else
            cout<<"0 0 0\n";
    }


    return 0;
}