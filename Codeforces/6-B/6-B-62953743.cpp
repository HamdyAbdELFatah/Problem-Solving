#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int n,m,sum=0;
    cin>>n>>m>>c;
    string s="";
    char arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    char t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            t=arr[i][j];
            if(t==c){
                if(i>0){
                    if(t!=arr[i-1][j]&&(arr[i-1][j]>='A'&&arr[i-1][j]<='Z')&&!(s.find(arr[i-1][j])+1)){
                        s+=arr[i-1][j];
                        sum++;
                    }
                } if(i<n-1){
                    if(t!=arr[i+1][j]&&(arr[i+1][j]>='A'&&arr[i+1][j]<='Z')&&!(s.find(arr[i+1][j])+1)){
                        s+=arr[i+1][j];
                        sum++;
                    }
                }if(j>0){
                    if(t!=arr[i][j-1]&&(arr[i][j-1]>='A'&&arr[i][j-1]<='Z')&&!(s.find(arr[i][j-1])+1)){
                        s+=arr[i][j-1];
                        sum++;
                    }
                } if(j<m-1){
                    if(t!=arr[i][j+1]&&(arr[i][j+1]>='A'&&arr[i][j+1]<='Z')&&!(s.find(arr[i][j+1])+1)){
                        s+=arr[i][j+1];
                        sum++;
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}