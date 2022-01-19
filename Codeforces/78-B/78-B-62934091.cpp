#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char arr[]={'R','O','Y','G','B','I','V'};
    for(int i=0;i<n;i++){

        if(i%7<3&&i>=n-3){
            cout<<arr[i%7+3];
        }else
            cout<<arr[i%7];
    }
        cout<<endl;
    return 0;
}