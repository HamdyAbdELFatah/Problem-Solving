//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
int main() {
	FIO;
	stack<char> s;
    string text;
    cin>>text;
    for (int i = 0; i < text.length(); ++i) {
		if(!s.empty() && text[i]==s.top())
			s.pop();
		else
			s.push(text[i]);
	}
    if(s.empty())
    	cout<<"Empty String\n";
    else{
    	string temp="";
    	while (!s.empty()) {
    		temp+=s.top();
    		s.pop();
		}
        reverse(temp.begin(), temp.end());
    	cout<<temp<<endl;
    }
	return 0;
}
