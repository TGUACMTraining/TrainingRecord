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

typedef struct//不保证哈希值及时更新    遵从左闭右开的规则
{
    const int key = 13;
    string str = {""};
    vector<unsigned long long> str_hash = {0};
    unsigned long long HASH(int begin)
    {
        int length = str_hash.size();
        int to = str.length() - begin;
        int times = to - length + 1;
        if (times > 0)
        {
            while (times--)
            {
                unsigned long long t = (*(str_hash.end() - 1));
                t *= key;
                t += (unsigned long long)str[str.length() - str_hash.size()];
                str_hash.push_back(t);
            }
            return (*(str_hash.end() - 1));
        }
        else
            return str_hash[str.length() - begin];
    }
    unsigned long long HASH(int begin, int end)
    {

        if (begin > end)
            return 0;
        unsigned long long ret = HASH(begin);

        ret -= HASH(end) * (unsigned long long)pow(key, end - begin);
        return ret;
    }
} string_;

int key=13;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int startTime = clock();
#endif
    // ios;
    /*code*/
    string_ a;
    a.str="ABCDEFG";
    cout<<a.HASH(0)<<endl;
    cout<<a.HASH(2)<<endl;

#ifndef ONLINE_JUDGE
    printf("Time = %dms\n", clock() - startTime);
#endif
    return 0;
}
