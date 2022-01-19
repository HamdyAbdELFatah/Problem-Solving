#include <bits/stdc++.h>
using namespace std;
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
int main() {
    FIO
    int t, l, r, n, m;
    cin>>n;
    ll arr [n];
    ll prefix[n + 1];
    cin>>arr[0];
    prefix[0]=0;
    prefix[1] = arr[0];
    for (int i = 1; i < n; i++) {
        cin>>arr[i];
        prefix[i + 1] = arr[i] + prefix[i];
    }
    sort(arr,arr+n);
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>t>>l>>r;
        if (t == 1) {
            cout<<prefix[r] - prefix[l - 1]<<"\n";
        } else if (t == 2) {
            if (l > 1) {
                cout<<arr[r - 1] - arr[l - 2]<<"\n";
            } else {
                cout<<arr[r - 1]<<"\n";
            }
        }
    }
  return 0;
}