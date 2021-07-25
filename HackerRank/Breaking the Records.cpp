#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
int main() {
    FIO;
    int n, max = -1, min = INF, s, a = -1, b = -1;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s > max) {
            max = s;
            a++;
        }
        if(s < min){
            min = s;
            b++;
        }
    }
    cout << a << " " << b <<endl;
    return 0;
}