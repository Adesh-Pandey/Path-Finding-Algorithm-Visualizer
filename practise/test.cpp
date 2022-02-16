#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int k = 0; k < n; k++)
    {
        cin >> arr[k];
    }
    const int N = 1e5 + 2;
    int idx[N];
    for (int l = 0; l < N; l++)
    {
        idx[l] = -1;
    }
    int minidx = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] == 1)
        {
            minidx = min(minidx, idx[arr[i]]);
        }
        else
        {
            idx[arr[i]] = 1;
        }
    }
    if (minidx == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << minidx + 1 << endl;
    }
    return 0;
}