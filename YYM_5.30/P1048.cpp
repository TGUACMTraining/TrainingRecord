#include <iostream>
using namespace std;
long long arr[110][1005];
long long val[110];
long long cost[110];
int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> cost[i] >> val[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int tt = 1; tt <= t; tt++)
        {
            arr[i][tt] = arr[i - 1][tt];
            if (tt - cost[i] >= 0)
            {
                arr[i][tt] = max(arr[i][tt], arr[i - 1][tt - cost[i]] + val[i]);
            }
        }
    }
    cout << arr[m][t];
}