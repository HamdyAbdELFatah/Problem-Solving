#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
using namespace std;
int main()
{
    FIO
    string s;
    cin>>s;
    int x=0,y=0,z=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='A'&&i<s.length()-1&&s[i+1]=='B')
        {
            x++;
            s[i+1]='C';
            if(i+1<s.length()&&s[i+2]=='A')
            {
                z++;
                s[i+2]='C';
            }
        }
        if(s[i]=='B'&&i<s.length()-1&&s[i+1]=='A')
        {
            y++;
            s[i+1]='C';
            if(i+1<s.length()&&s[i+2]=='B')
            {
                z++;
                s[i+2]='C';
            }
        }
    }
    if(x&&y)
        cout<<"YES\n";
    else if((x>1&&z)||(y>1&&z))
        cout<<"YES\n";
    else
        cout<<"NO";
    return 0;
}