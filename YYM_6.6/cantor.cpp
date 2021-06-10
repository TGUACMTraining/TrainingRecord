#include <iostream>
using namespace std;
const int limit = 1000000 + 100;
int n;
int a[limit], c[limit];
int MOD = 998244353;
int main()
{
    cin >> n;
    for (int i = n; i; i--)
    {
        cin >> a[i];
    }
    int ans = 0;
    int m = 1;
    for (int i = 1; i <= n; i++)
    {
        int A = 0;
        for (int j = a[i]; j; j -= j & -j)
            A += c[j];
        ans = (ans +1ll* A * m) % MOD, m = (1ll*i * m) % MOD;
        for (int j = a[i]; j <= n; j += j & -j)
            c[j]++;
    }
    cout << ans + 1 << endl;
}