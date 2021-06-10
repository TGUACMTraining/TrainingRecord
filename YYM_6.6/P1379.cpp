#include<cstring>
#include<iostream>
using namespace std;
const int len=9;
int fac[10];
enum{pos,rev};
int cantor(int arr[]){
    int ans=0,c[15]={0};
    for(register int i=len;i;--i){
        register int a=0;
        for(register int j=arr[i];j;j-=j&-j)a+=c[j];
        ans+=a*fac[len-i];
        for(register int j=arr[i];j<=len;j+=j&-j)++c[j];
    }
    return ans;
}
struct PST{
    int x,y;
};
struct ARR
{
    int arr[9];
    ARR(){
        memset(arr,0,sizeof(arr));
    }
};
const int limit=4e5+10;
struct state{
    ARR a;
    PST pst;
    int step;
};
short visited[limit];
int steps[limit];
struct Q{
    state arr[limit];
    int head,tail;
    void push(ARR& a,PST p,int step){
        arr[tail++]={a,p,step};
    }
    void pop(){
        head++;
    }
    state& front(){
        return arr[head];
    }
    Q(){
        head=0;
        tail=0;
        memset(arr,0,sizeof(arr));
    }
    int size(){
        return tail-head;
    }
}q[2];
int cd[]={0,1,0,-1,0};
int bfs(){
    while(true){
        int mode=q[0].size()>q[1].size()?0:1;
        auto & now=q[mode].front();
        for(int i=0;i<=4;i++){
            int xx=now.pst.x+cd[i];
            int yy=now.pst.y+cd[i+1];
            if(xx>=0&&yy>=0&&xx<3&&yy<3){
                int ct=cantor(now.a.arr);
                if(visited[ct]==-1){
                    visited[ct]=mode;
                    ARR a=now.a;
                    swap(a.arr[now.pst.x*3+now.pst.y],a.arr[xx*3+yy]);
                    steps[ct]=now.step+1;
                    q[mode].push(a,{xx,yy},now.step+1);
                }else if(visited[ct]!=mode){
                    return steps[ct]+now.step+1;
                }
            }
        }
        q[mode].pop();
    }
}
int main(){
    ARR a;
    ARR b;
    int arr[]={1,2,3,8,9,4,7,6,5};
    for(int i=0;i<9;i++){
        b.arr[i]=arr[i];
    }
    PST k;
    int j;
    for(int i=0;i<9;i++){
        scanf("%1d",a.arr+i);
        if(a.arr[i]==0){a.arr[i]=9;j=i;break;}
    }k.x=j/3;k.y=j%3;
    q[pos].push(a,k,0);
    q[rev].push(b,{1,1},1);
    printf("%d",bfs());
}