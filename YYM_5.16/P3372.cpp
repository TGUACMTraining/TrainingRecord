#include <iostream>
using namespace std;
typedef long long ll;
const ll limit = 1e5 + 10;
ll d1[limit], d2[limit];
ll n, m;
void r(ll &x)
{
    scanf("%ld", &x);
}
void p(ll x){
    printf("%ld\n",x);
}
void add(ll pos, ll d)
{
    for (ll i = pos; i <= n; i += i & -i)
    {
        d1[i] += d;
        d2[i] += d * pos;
    }
}
void add(ll from, ll to, ll d)
{
    add(from, d);
    add(to + 1, -d);
}
ll ask(ll pos)
{
    ll ans = 0;
    for (ll i = pos; i; i -= i & -i)
    {
        ans += d1[i] * (pos+1) - d2[i];
    }
    return ans;
}
ll cache[limit];
main()
{
    r(n);
    r(m);
    for (ll i = 1; i <= n; i++)
    {
        r(cache[i]);
    }
    for (ll i = n; i >= 1; i--)
    {
        cache[i] -= cache[i - 1];
    }
    for (ll i = 1; i <= n; i++)
    {
        add(i, cache[i]);
    }
    while (m--)
    {
        ll mode;
        r(mode);
        ll x, y, k;
        switch (mode)
        {
        case 1:
            r(x), r(y), r(k);
            add(x, y, k);
            break;

        default:
            r(x), r(y);
            p(ask(y) - ask(x - 1));
            break;
        }
    }
}