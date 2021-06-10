#include <cstdio>
int dp[1010][210][210][2];
char a[1010], b[210];
int n, m, k;
int main()
{
    scanf("%d%d%d%s%s", &n, &m, &k, a + 1, b + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i - 1][0][0][0] = 1;
            for (int kk = 1; kk <= k; kk++) {
                if (a[i] == b[j]) {
                    dp[i][j][kk][0] = dp[i - 1][j][kk][0] + dp[i - 1][j][kk][1];
                    dp[i][j][kk][1] = dp[i - 1][j - 1][kk][1] + dp[i - 1][j - 1][kk - 1][0] + dp[i - 1][j - 1][kk - 1][1];
                } else {
                    dp[i][j][kk][0] = dp[i - 1][j][kk][0] + dp[i - 1][j][kk][1];
                    dp[i][j][kk][1] = 0;
                }
            }
        }
    }
    printf("%d\n", (dp[n][m][k][0] + dp[n][m][k][1]));
    return 0;
}