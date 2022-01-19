#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<char> s;
    string x;
    cin>>x;
    for(int i=0;i<x.length();i++)
        s.insert(x[i]);
    string result=(s.size()%2==0)?"CHAT WITH HER!":"IGNORE HIM!";
    cout<<result<<endl;
    return 0;
}