#include <iostream>
#include <cstring>
using namespace std;
int arr[(int)2e5 + 10];
long long f[(int)2e5 + 10];
long long n, w, ans;
bool jud(int k)
{
    memset(f, 0, sizeof(f));
    for (int i = k; i <= n - k + 1; i++)
    {
        f[i] = max(f[i - k] + arr[i], f[i - 1]);
    }
    if (f[n - k + 1] >= w)
        return 1;
    else
        return 0;
}
void work(int x, int y)
{
    if (x == y)
    {
        ans = x;
        return;
    }
    int mid = (x + y + 1) / 2;
    if (jud(mid))
    {
        work(mid, y);
    }
    else
    {
        work(x, mid-1);
    }
}
int main()
{
    scanf("%lld%lld", &n, &w);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if(!jud(1)){
        printf("-1");
        return 0;
    }
    work(1,n+1);
    printf("%lld",ans);
    //tepan
}