#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int N = 1e5 + 10;
int a[N], b[N];

int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] + b[i - 1];
    }
    
    while(m --)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", b[r] - b[l - 1]);
    }
    return 0;
}
