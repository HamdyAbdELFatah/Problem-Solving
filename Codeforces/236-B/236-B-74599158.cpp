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
    int x,_count=0,A,B,C;
    cin>>A>>B>>C;;
    int i;
    for(int a=1; a<=A; a++)
        for(int b=1; b<=B; b++)
            for(int c=1; c<=C; c++)
            {
                x=a*b*c;
                for( i=1; i*i<x; i++)
                    if(x%i==0)
                    {
                        _count+=2;
                    }
                if(i*i == x)
                    _count++;
            }
    cout <<_count<<endl;
    return 0;
}