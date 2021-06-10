#include<iostream>  
using namespace std;
struct STK
{
    int BEGIN;
    int END;
    int head;
    int tail;
    int size;
}stk[(int)1e5+10];
struct LST{
    int next[2]={0};
    int change_mode=0;
    int val;
}lst[(int)1e5+10];
enum{fw=1,bw=-1};
enum{pre,nxt};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        memset(stk,0,sizeof(stk));
        memset(lst,0,sizeof(lst));
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            stk[i].head=++cnt;
            stk[i].tail=cnt;
            lst[cnt].val=i;
            stk[i].BEGIN=fw;
            stk[i].END=fw;
            stk[i].size=1;
        }
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(!stk[x].size)continue;
            if(stk[x].END!=stk[y].END){
                lst[stk[x].tail].change_mode=0;
            }else{
                lst[stk[x].tail].change_mode=1;
            }
            lst[stk[y].tail].next[nxt]=stk[x].tail;
            lst[stk[x].tail].next[pre]=stk[y].tail;
            stk[y].tail=stk[x].head;
            stk[y].END=-stk[x].BEGIN;
            stk[y].size+=stk[x].size;
            stk[x]={0,0,0,0,0};

        }
        for(int i=1;i<=n;i++){
            printf("%d ",stk[i].size);
            int read_mode=nxt;
            for(int j=stk[i].head;j!=0;j=lst[j].next[read_mode]){
                printf("%d ",lst[j].val);
                if(lst[j].change_mode == 1) read_mode = pre;
            }printf("\n");
        }
    }
}