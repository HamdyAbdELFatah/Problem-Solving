#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &x, const string &y)
{
    int n=x.length()+1;
    int m=y.length()+1;
    int arr[n][m];
    arr[0][0]=0;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(i==1)arr[i-1][j]=j;
            if(j==1)arr[i][j-1]=i;
            if(x[i-1]!=y[j-1])
                arr[i][j]=min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]))+1 ;
            else
                arr[i][j]=arr[i-1][j-1];
        }
    }
    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
          cout << arr[i][j] << "  " ;
        }
            cout << endl;
    }*/
    return arr[n-1][m-1];
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}
