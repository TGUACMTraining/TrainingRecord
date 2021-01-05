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
// #define ONLINE_JUDGE
#pragma GCC optimize(2)
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
#define dbg(x)                                          \
    {                                                   \
        cout << "In line " << __LINE__ << endl;         \
        x                                               \
                cout                                    \
            << "-----------------" << __LINE__ << endl; \
    }
#else
#define dbg(x)
#endif

int cmpstr(string a, string b);
string Fix(string s);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int startTime = clock();
#endif
    // ios_;
    int result;
    string a, b;
    string cache;
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin,cache);
		while (getline(cin,cache) &&cache != "END")
		{
				a = a +cache; a += '\n';
		}
		getline(cin,cache);
		while (getline(cin,cache) &&cache != "END")
		{
				b = b +cache; b += '\n';
		}
        result = cmpstr(a, b);
		a.clear(); b.clear();
        switch (result)
        {
        case 1:
            cout << "Accepted" << endl;
            break;
        case 0:
            cout << "Presentation Error" << endl;
            break;
        case -1:
            cout << "Wrong Answer" << endl;
            break;
        default:
            break;
        }
    }
    dbg(
        a = "1234567 ";
        b = "1233567";)

#ifndef ONLINE_JUDGE
        printf("Time = %dms\n", clock() - startTime);
#endif
    return 0;
}

int cmpstr(string a, string b)
{
    int flag = 0;
	int reallen1=0, reallen2=0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '\t') reallen1 = reallen1 + 3;
	}
	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] == '\t') reallen2 = reallen2 + 3;
	}
	reallen1 += a.length(); reallen2 += b.length();
	if (reallen1 == reallen2)
	{
		for (int i = 0; i < a.length();i++)
		{
			if (a[i] != b[i]) flag++;
		}
		if (flag != 0) return -1;
		else return 1;
	}
	else
	{
		part1:if (Fix(a) == Fix(b)) return 0;
		else return -1;
	}
}
string Fix(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]==' '||s[i]=='\t'|| s[i] == '\n')
		{
			s.erase(i, 1);
			i = i - 1;
		}
	}
	return s;
}