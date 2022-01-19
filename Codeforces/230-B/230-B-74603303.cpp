#include <bits/stdc++.h>
using namespace std;
void init()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}
int main()
{
    init();
    long long n,x;
    cin>>n;
    for(long long i=1; i<=n; i++){
        cin>>x;
        if(x%2==0)
            if(x==4)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        else {
            long long s=sqrt(x);
            int f=0;
            if(s*s==x&&x>1){
                 for(int j=3;j*j<=s;j+=2)
                    if(s%j==0){
                        f=1;
                        break;
                    }
                 if(f)
                     cout<<"NO\n";
                 else
                    cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}