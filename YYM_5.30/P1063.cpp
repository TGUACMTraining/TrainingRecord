#include <iostream>
using namespace std;
int n;
int a[210];
int b[210];
long long dp[210][210];
#define rg register 
int main()
{
    scanf("%d", &n);
    for (rg int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (rg int i = 1 + n; i <= 2 * n; i++) {
        a[i] = a[i - n];
    }
    for (rg int i = 1; i <= n; i++) {
        b[i] = a[i + 1];
    }
    for (rg int i = n + 1; i <= 2 * n; i++) {
        b[i] = b[i - n];
    }
    long long ans=0;
    for(rg int len=1;len<=n;len++){
        for(rg int from=1,to;(to=from+len-1)<=2*n;from++){
            for(rg int cut=from;cut<to;cut++){
                dp[from][to]=max(dp[from][to],dp[from][cut]+dp[cut+1][to]+1ll*a[from]*b[cut]*b[to]);
            }
        }
    }
    for(int from=1;from<=n;from++)
        ans=max(ans,dp[from][from+n-1]);
    printf("%lld",ans);

}