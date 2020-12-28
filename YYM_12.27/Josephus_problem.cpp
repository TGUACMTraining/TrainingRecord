#include <algorithm>
#include <bitset>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #define debug
#define ONLINE_JUDGE

const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
#define memset0(x) memset(x, 0, sizeof(x))
#define memsetM1(x) memset(x, -1, sizeof(x))
#define memsetINF(x) memset(x, 0x3f, sizeof(x))
#define memsetNINF(x) memset(x, 0xcf, sizeof(x))
#define ios_                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#ifdef debug
#define dbg(x)                                           \
    {                                                    \
        cout << "In line " << __LINE__ << endl;          \
        x;                                               \
        cout << "-----------------" << __LINE__ << endl; \
    }
#else
#define dbg(x)
#endif

int n;
int m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int startTime = clock();
#endif
    ios_;
    /*code*/
    cin >> n >> m;
    dbg(
        cout<<"get"<<"n="<<n<<"m="<<m<<endl;
    )
    list<int> li;
    dbg(
        cout<<"li created"<<endl;
    )
    for (int i = 0; i < n; i++)
    {
        li.push_back(i + 1);
        dbg(
            cout<<i+1<<endl;
        )
    }
    int count = 0;
    list<int>::iterator p = li.begin();
    while (li.size() != 1)
    {
        if (p == li.end())
        {
            p = li.begin();
        }
        if (count == m-1)
        {
            cout<<*p<<" ";
            p=li.erase(p);
        }else{
            p++;
        }
        count=(count+1)%(m);
        dbg(
            cout<<"caculating"<<endl;
            cout<<"size="<<li.size()<<endl;
        )
    }
    cout<<*(li.begin())<<endl;
#ifndef ONLINE_JUDGE
    printf("Time = %dms\n", clock() - startTime);
#endif
    return 0;
}

/*code*/