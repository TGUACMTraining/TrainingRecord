#include <bits/stdc++.h>
using namespace std;
#define limit (int)1e7
int gcd(int a, int b);
int main()
{
    int n, m;
    cin >> n >> m;
    int *fz = new int[n + 1];
    int *fm = new int[m + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> fz[i];
    }
    fz[n] = 0;
    for (int i = 0; i < m; i++)
    {

        cin >> fm[i];
    }
    fm[m] = 0;

    int ind_fz = 1;
    int index = 0;
    while (fz[ind_fz])
    {
        if (fz[ind_fz] * fz[index] > limit)
        {
            index++;
            fz[index] = 1;
        }
        fz[index] *= fz[ind_fz];
        ind_fz++;
    }
    fz[index + 1] = 0;
    index=0;
    int ind_fm = 1;
    while (fm[ind_fm])
    {
        if (fm[ind_fm] * fm[index] > limit)
        {
            index++;
            fm[index] = 1;
        }
        fm[index] *= fm[ind_fm];
        ind_fm++;
    }
    fm[index + 1] = 0;
    ind_fz = 0;
    stack<int> ans_fz;
    stack<int> ans_fm;
    while (fz[ind_fz])
    {
        ind_fm = 0;
        while (fm[ind_fm])
        {
            int g = gcd(fz[ind_fz], fm[ind_fm]);
            fz[ind_fz] /= g;
            fm[ind_fm] /= g;
            ind_fm++;
        }
        ind_fz++;
    }
    ind_fz = ind_fm = 0;
    while (fz[ind_fz])
    {
        if (fz[ind_fz] != 1)
        {
            ans_fz.push(fz[ind_fz]);
        }
        ind_fz++;
    }
    while (fm[ind_fm])
    {
        if (fm[ind_fm] != 1)
        {
            ans_fm.push(fm[ind_fm]);
        }
        ind_fm++;
    }
    if (!ans_fz.size())
        ans_fz.push(1);
    if (!ans_fm.size())
        ans_fm.push(1);
    cout << ans_fz.size() << " " << ans_fm.size() << endl;
    while(!ans_fz.empty()){
        cout<<ans_fz.top()<<" ";
        ans_fz.pop();
    }
    while(!ans_fm.empty()){
        cout<<ans_fm.top()<<" ";
        ans_fm.pop();
    }
    return 0;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}