#include<vector>
#include<queue>
#include<iostream>
using namespace std;
struct state{
    int x,y;
    int dir;
    int t;
};
int des[2];
enum{E,S,W,N};
int cd[]={0,1,0,-1,0};

int n,m;
int map[60][60];
void r(int &x){
    scanf("%d",&x);
}
bool visited[60][60][4];
bool collide(int x,int y,int xx,int yy){
    if(xx<=0||yy<=0||x<=0||y<=0||x>=n||y>=m||xx>=n||yy>=m)return false;
    if(x>xx)swap(x,xx);
    if(y>yy)swap(y,yy);
    for(int i=x;i<=xx;i++){
        for(int j=y;j<=yy;j++){
            if(map[i][j]||map[i][j+1]||map[i+1][j]||map[i+1][j+1])
            return false;
        }
    }return true;
}
bool next_state(int mode,state &change,const state o){
    change=o;
    switch (mode)
    {
    case 0:
        change.x+=cd[change.dir];
        change.y+=cd[change.dir+1];
        break;
    case 1:
        change.dir++;
        change.dir%=4;
        break;
    case 2:
        change.dir+=3;
        change.dir%=4;
        break;
    case 3:
        change.x+=cd[change.dir]*3;
        change.y+=cd[change.dir+1]*3;
        break;
    case 4:
        change.x+=cd[change.dir]*2;
        change.y+=cd[change.dir+1]*2;
        break;
    }
    change.t+=1;
    return collide(o.x,o.y,change.x,change.y);
}
struct Q
{
    state arr[(int)3e5+10];
    int from[(int)3e5+10];
    int head;
    int tail;
    void push(state val){
        from[tail]=head;
        arr[tail++]=val;
    }
    void pop(){
        head++;
    }
    state front(){
        return arr[head];
    }
    bool empty(){
        return head-tail==0;
    }
    void print(){
        tail--;
        while(tail!=0){
            printf("t:%d x:%d y:%d\n",arr[tail].t,arr[tail].x,arr[tail].y);
            tail=from[tail];
        }
    }
}q;

int time(){
    while(!q.empty()){
        const state &s=q.front();
        if(s.x==des[0]&&s.y==des[1])return s.t;
        for(int i=0;i<5;i++){
            state nd;
            if(next_state(i,nd,s)){
                if(!visited[nd.x][nd.y][nd.dir]){
                    visited[nd.x][nd.y][nd.dir]=true;
                    q.push(nd);
                    if(nd.x==des[0]&&nd.y==des[1])
                    return nd.t;
                }
            }
        }q.pop();
    }return -1;
}
int main(){
    r(n);r(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            r(map[i][j]);
        }
    }
    int x,y;
    char dire;
    scanf("%d%d%d%d %c",&x,&y,&des[0],&des[1],&dire);
    int d;
    switch (dire)
    {
    case 'E':
        d=E;
        break;
    case 'W':
        d=W;
        break;
    case 'S':
        d=S;
        break;
    case 'N':
        d=N;
        break;
    }
    visited[x][y][d]=true;
    q.push({x,y,d,0});
    printf("%d\n",time());
    // q.print();
}