#include <bits/stdc++.h>
using namespace std;
int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int n=a.size()+1;
    int m=b.size()+1;
    int l=c.size()+1;
    int arr[n][m][l];
    arr[0][0][0]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<l; k++)
            {
                if (i == 0 || j == 0||k==0)
                    arr[i][j][k] = 0;
                else if(a[i-1]==b[j-1]&&a[i-1]==c[k-1])
                    arr[i][j][k]=arr[i-1][j-1][k-1]+1;
                else
                    arr[i][j][k]=max(max(arr[i-1][j][k],arr[i][j-1][k]),arr[i][j][k-1]);
            }

        }
    }
    return arr[n-1][m-1][l-1];
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

    size_t cn;
    cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++)
    {
        cin >> c[i];
    }
    cout << lcs3(a, b, c) << endl;
}
