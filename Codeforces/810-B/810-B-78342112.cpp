#include <iostream>
#include <math.h>
#include <set>
#include <iterator>
#define ull unsigned long long
using namespace std;
int main()
{
    ull sum=0,f,n,k,l;
    multiset <int,greater<ull>> s;
    cin>>n>>f;
    while(n--){
        cin>>k>>l;
        if(k>=l){
            sum+=l;
            s.insert(0);
        }else{
            sum+=k;
            s.insert((2*k>l)?(l-k):k);
        }
    }
 
    auto it=s.begin();
    for(auto i=0;i<f;i++){
        sum+=*it;
        it++;
    }
 
    cout<<sum<<endl;
    return 0;
}