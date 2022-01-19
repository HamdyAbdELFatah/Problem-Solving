#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0);
#define ll long long
using namespace std;
int main()
{
    FIO
    int n,max=0;
    cin>>n;
    int arr[n],result[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]>max){
            result[i]=0;
            max=arr[i];
        }else{
            result[i]=max-arr[i]+1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}