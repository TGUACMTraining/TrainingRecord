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
        x                                                \
        cout << "-----------------" << __LINE__ << endl; \
    }
#else
#define dbg(x)
#endif

/*code*/
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int startTime = clock();
#endif
    // ios::sync_with_stdio(0);
    int arr2[2010];
    int arr[2010];
    int t2,t1;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        t1=t2=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            if(a&1)arr[t1++]=a;
            else arr2[t2++]=a;
        }
        ans=(n-1+t1)*(n-t1)/2;
        sort(arr,arr+t1,greater<int>());
        for(int i=0;i<t1;i++){
            for(int j=i+1;j<t1;j++){
                if(gcd(arr[i],arr[j])!=1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

#ifndef ONLINE_JUDGE
    printf("Time = %dms\n", clock() - startTime);
#endif
    return 0;
}

/*code*/