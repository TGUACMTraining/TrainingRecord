#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<ctime>
using namespace std;
#define DBG
#ifdef DBG
#define dbg(x) \
{\
    cout<<"------------"<<endl;\
    cout<<__LINE__<<endl;\
    cout<<__LINE__<<endl;\
    cout<<"------------"<<endl;\
}
#else
#define dbg(x)
#endif
char guidao[110][1100];
int tail[110];
char stk[(int)1e5];
int stk_tail;
int n,m,s;
char res[(int)1e5];
int t;
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin>>guidao[i][j];
        }
    }
    int num;
    while(cin>>num,num!=-1){
        if(num!=0){
            if(stk_tail==s){res[t++]=stk[--stk_tail];}
            if(tail[num]!=m)
            stk[stk_tail++]=guidao[num][tail[num]++];
        }
        else{
            if(stk_tail!=0)
            res[t++]=stk[--stk_tail];
        }
    }
    for(int i=0;i<t;i++){
        cout<<res[i];
    }
}