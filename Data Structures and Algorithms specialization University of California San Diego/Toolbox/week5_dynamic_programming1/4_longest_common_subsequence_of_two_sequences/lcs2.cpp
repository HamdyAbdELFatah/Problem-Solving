#include <bits/stdc++.h>
using namespace std;
int lcs2(vector<int> &a, vector<int> &b)
{
    int n=a.size()+1;
    int m=b.size()+1;
    int arr[n][m];
    arr[0][0]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if(a[i-1]==b[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);


        }
    }
    return arr[n-1][m-1];
}

int main()
{
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    size_t m;
    cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    cout << lcs2(a, b) << endl;
}
