#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,sum=0,m=INT_MAX,c=1,y=0,j=0;;
    cin>>n>>k;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
        if(c<=k){
            sum+=x[i];
            c++;
            m=sum;
            y=1;
        }else {
            sum+=x[i]-x[j];
            if(m>sum){
                m=sum;
                y=i+2-k;
            }
            j++;
        }

    }
    cout<<y<<endl;
    return 0;
}