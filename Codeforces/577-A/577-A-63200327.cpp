#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   unsigned long long int n,x,c=0,i;
   cin>>n>>x;
   for( i=1;i<=n;i++)
   {
       if(i*n>=x)
        if(x%i==0)c++;
   }
   cout<<c;
}