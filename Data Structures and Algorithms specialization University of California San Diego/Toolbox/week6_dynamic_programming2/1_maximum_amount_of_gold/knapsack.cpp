#include <bits/stdc++.h>
using namespace std;

int optimalWeight(int W, vector<int> v, vector<int> w, int n)
{

    vector<vector<int>>  arr(n + 1,vector<int>(W + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (w[i - 1] <= j)
                arr[i][j] = max(v[i - 1] + arr[i - 1][j - w[i - 1]],arr[i - 1][j]);
            else
                arr[i][j] = arr[i - 1][j];
        }
    }

    return arr[n][W];
}

int main()
{
    int n, W;
    cin >> W >> n;
    vector<int> v(n);
    vector<int> w(n);
    int x;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
        w[i]=x;
    }
    cout << optimalWeight(W, v, w, n) << endl;
}
