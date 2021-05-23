#include <iostream>
using namespace std;
#define ll long long
#define mm ll mid = (l + r) >> 1;
const ll MAX = 1e5 + 10;
ll n, m, a[MAX], ans[MAX << 2], tag[MAX << 2];
ll inline L(ll p) { return p << 1; };
ll inline R(ll p) { return p << 1 | 1; }
#define lp L(p)
#define rp R(p)
void pushUp(ll p)
{
    ans[p] = ans[lp] + ans[rp];
}
void buildTree(ll p, ll l, ll r)
{
    tag[p] = 0;
    if (l == r)
    {
        ans[p] = a[l];
        return;
    }
    mm;
    buildTree(lp, l, mid);
    buildTree(rp, mid + 1, r);
    pushUp(p);
}
void changeNode(ll p, ll l, ll r, ll k)
{
    ans[p] += k * (r - l + 1);
    tag[p] += k;
}
void pushDown(ll p, ll l, ll r)
{
    mm;
    changeNode(lp, l, mid, tag[p]);
    changeNode(rp, mid + 1, r, tag[p]);
    tag[p] = 0;
}
void change(ll nl, ll nr, ll l, ll r, ll p, ll k)
{
    if (nl <= l && r <= nr)
    {
        changeNode(p, l, r, k);
        return;
    }
    pushDown(p, l, r);
    mm;
    if (l <= mid)
        change(nl, nr, l, mid, lp, k);
    if (r > mid)
        change(nl, nr, mid + 1, r, rp, k);
    pushUp(p);
}
ll query(ll al, ll ar, ll l, ll r, ll p)
{
    if (al <= l && ar <= r)
        return ans[p];
    mm;
    ll res = 0;
    if (l <= mid)
        res += query(al, ar, l, mid, lp);
    if (r > mid)
        res += query(al, ar, mid + 1, r, rp);
    return res;
}
main()
{
}