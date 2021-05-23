#include <iostream>
using namespace std;
const int limit = 1e3 + 10;
char str[limit];
int n;
enum
{
    ALICE,
    BOB,
    DRAW
};
pair<int, int> jud(int n)
{
    if (n == 1)
        return {1, 0};
    if (n == 2)
        return {2, 0};
    pair<int, int> p;
    if (n & 1)
    {
        p = jud(n - 1);
        swap(p.first,p.second);
        p.first++;
    }
    else{
        p=jud(n-1);
        swap(p.first,p.second);
        p.first++;
    }
    return p;
}
int ans(pair<int,int>p){
    if(p.first==p.second)return DRAW;
    if(p.first>p.second)return BOB;
    else return ALICE;
}
int getn()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> str;
        switch (ans(jud(getn())))
        {
        case ALICE:
            cout << "ALICE" << endl;
            break;
        case BOB:
            cout << "BOB" << endl;
            break;
        default:
            cout << "DRAW" << endl;
            break;
        }
    }
}