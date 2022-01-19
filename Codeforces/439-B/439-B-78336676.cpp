#include <iostream>
#include <math.h>
#include <set>
#include <iterator>
using namespace std;
int main()
{
    unsigned long long sum=0,x,n,c;
    multiset <int> s;
    cin>>n>>x;
    while(n--){
        cin>>c;
        s.insert(c);
    }
    for(auto i=s.begin();i!=s.end();i++){
        sum+=*i * x;
        if(x>1)
            x--;
    }

    cout<<sum<<endl;
    return 0;
}