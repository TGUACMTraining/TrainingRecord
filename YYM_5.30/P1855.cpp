#include <iostream>
using namespace std;
const int limit = 110;
int m[limit], t[limit];
int res[limit][210][210];
int main()
{
    int n, M, T;
    cin >> n >> M >> T;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i] >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int mm = 1; mm <= M; mm++)
        {
            for (int tt = 1; tt <= T; tt++)
            {
                res[i][mm][tt] = res[i - 1][mm][tt];
                if (mm - m[i] >= 0 && tt - t[i] >= 0)
                {
                    res[i][mm][tt] = max(res[i][mm][tt], res[i - 1][mm - m[i]][tt - t[i]] + 1);
                }
            }
        }
    }
    cout<<res[n][M][T];
}