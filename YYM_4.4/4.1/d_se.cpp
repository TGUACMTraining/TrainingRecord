#include<iostream>
#include<cstring>
using namespace std;
unsigned int arr[(int)1.1e5];
int solved[(int)1.1e5];
bool e[(int)1.1e5];
int tail=1;
int main(){
    int n,m;
    ios::sync_with_stdio(0);
    cin>>n>>m;
    memset(arr,-1,sizeof(arr));
    arr[0]=0;
    for(int step=1;step<=n;step++){
        int mode,xi,times;
        cin>>mode;
        int t=tail;
        switch (mode)
        {
        case 1:
            cin>>xi>>times;
            xi=(xi+99999)/100000;
            for(int tr=0;tr<t;tr++){
                int cache= solved[tr];
                for(int time=0;time<times;time++){
                    cache+=xi;
                    if(cache>m)break;
                    if(!e[cache]){solved[tail++]=cache;e[cache]=1;arr[cache]=step;}
                    else break;
                }
            }
            break;
        
        default:
            cin>>xi>>times;
            for(int tr=1;tr<t;tr++){
                int cache=solved[tr];
                for(int time=1;time<=times;time++){
                    cache=(((unsigned int)cache)*xi+99999)/100000;
                    if(cache>m)break;
                    if(!e[cache]){solved[tail++]=cache;e[cache]=1;arr[cache]=step;}
                    else break;
                }
            }
            break;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<(int)arr[i]<<" ";
    }
}