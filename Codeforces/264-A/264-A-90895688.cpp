#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
int main() {
    string str;
    cin>>str;
    stack<int>s;
    for(unsigned int i = 0; i < str.size(); i++){
        if(str[i] == 'l')
            s.push(i+1);
        else
            cout<<i+1<<endl;
    }
 
 
 
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}