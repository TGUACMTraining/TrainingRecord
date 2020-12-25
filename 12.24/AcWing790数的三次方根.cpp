```
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

double n;

int main(void)
{
    cin >> n;
    int flag = 1;
    if (n < 0)
    {
        n = -n;
        flag = 0;
    }
    double l = 0, r = n;
    while(r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > n)    r = mid;
        else    l = mid;
    }
    if (flag)
        printf("%.6f", l);
    else
        printf("-%.6f", l);
    return 0;
}
