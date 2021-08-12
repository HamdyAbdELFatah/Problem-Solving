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
	int alphabet[26]={0};
	char c;
	while(cin>>c){
		c = tolower(c);
		alphabet[c-97]=1;
	}
	int count =0;
	for (int i = 0; i < 26; ++i) {
		if(alphabet[i]==1)
			count++;
	}
	if(count==26)
		cout<<"pangram\n";
	else
		cout<<"not pangram\n";
	return 0;
}
