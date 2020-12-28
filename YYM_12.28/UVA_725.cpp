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

int arr[10]={0};
vector<int> number;
int k=0;
int times;
void search_(int k/*搜索深度*/);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int startTime = clock();
#endif
    // ios;
    /*code*/
    cin>>times;
    search_(0);

#ifndef ONLINE_JUDGE
    printf("Time = %dms\n", clock() - startTime);
#endif
    return 0;
}
void search_(int k/*搜索深度*/){
    
    for(int p=0;p<10;p++){
        dbg(
            cout<<"\t\t\t\t\t\t\t\t\tlevel="<<k<<endl;
            for(int i=0;i<10;i++){
                cout<<arr[i]<<"\t";
            }cout<<endl;
            for(int i=0;i<number.size();i++){
                cout<<number[i]<<"\t";
            }cout<<endl;
        )
        if(!arr[p]){
            number.push_back(p);
            arr[p]=1;
            if(k==4){
                int a;
                int b;
                a=number[0]+number[1]*10+number[2]*100+number[3]*1000+number[4]*10000;
                dbg(
                    cout<<"a="<<a<<endl;
                )
                b=times*a;
                int cache[5]={0};
                int flag=1;
                if(b<100000){
                    dbg(
                        cout<<"b="<<b<<endl;
                        for(int i=0;i<10;i++){
                            cout<<arr[i]<<"\t";
                        }cout<<endl;
                    )
                
                    for(int i=0;i<5;i++){
                        cache[i]=b%10;
                        b/=10;
                    }
                    int judge[10]={0};
                    for(int  i=0;i<5;i++){
                        if(judge[cache[i]]||arr[cache[i]])
                        {
                            flag=0;
                            break;
                        }else{
                            judge[cache[i]]=1;
                        }
                    }
                    dbg(
                        for(int i=0;i<5;i++){
                            cout<<cache[i]<<"\t";
                        }cout<<endl;
                    )
                    if(flag==1){
                        printf("%05d/%05d=%d\n",a*times,a,times);
                    }
                }
            }
            else{
                 search_(k+1);
            }
            arr[p]=0;
            number.pop_back();

        }
    }
}
/*code*/
