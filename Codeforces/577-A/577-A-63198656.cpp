#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,x,c=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
       if(x%i==0&&x<=i*n)
            if(i==1&&x<=n)
                c++;
            else if(i!=1){
                c++;
            }
    }
    cout<<c<<endl;
}