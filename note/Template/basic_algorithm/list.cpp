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
#define debug
// #define ONLINE_JUDGE

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
        x                                                \
        cout << "-----------------" << __LINE__ << endl; \
    }
#else
#define dbg(x)
#endif

typedef struct{
    int to ;
    int value;
}edge;

vector <list<edge> >points;




int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int startTime = clock();
#endif
    // ios;
    /*code*/
    edge x={0,1};
    list<edge> cache;
    cache.push_back(x);
    points.push_back(cache);
    list<edge>::iterator p;
    p=points[0].begin();
    cout<<(*p).to<<(*p).value<<endl;
    x.to=4;
    x.value=5;
    cache.push_back(x);
    cout<<(*(++p)).to<<(*(p--)).value<<endl;
    points[0].push_back(x);
    cout<<(*(++p)).to<<(*(p)).value<<endl;
#ifndef ONLINE_JUDGE
    printf("Time = %dms\n", clock() - startTime);
#endif
    return 0;
}

/*code*/