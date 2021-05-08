#include <iostream>
#include <algorithm>
using namespace std;
long long l[(long long)1e6 + 10];
long long r[(long long)1e6 + 10];
long long ind[(long long)1e6 + 10];
long long n;
bool cmp(long long a, long long b)
{
    return l[a] < l[b];
}
bool judge(long long len)
{
    long long tp = 0;
    for (long long i = 1; i < n; i++)
    {
        long long np = tp + len;
        if (np > r[ind[i]])
        {
            return false;
        }
        else
        {
            tp = max(tp + len, l[ind[i]]);
        }
    }
    return true;
}
int main()
{
    cin >> n;
    long long a = 1, b = (long long)2e9+10;
    for (long long i = 0; i < n; i++)
    {
        cin >> l[i];
        cin >> r[i];
        r[i] += l[i];
        b=max(b,r[i]);
    }
    b+=100;
    for (long long i = 0; i < n; i++)
    {
        ind[i] = i;
    }
    sort(ind, ind + n, cmp);
    while (a < b)
    {
        long long mid = (a + b + 1) / 2;
        if (!judge(mid))
        {
            b = mid - 1;
        }
        else
        {
            a = mid;
        }
    }
    cout << a << endl;
}