#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int map[405][405];
struct dot{
    int x,y;
}q[400*405];
int head,tail;
int d[][2]={
    {1,2},
    {2,1},
    {-1,-2},
    {-2,-1},
    {-1,2},
    {-2,1},
    {1,-2},
    {2,-1},
};
int cnt;
void bfs(){
    while(head!=tail){
        dot&dt=q[tail];
        for(int i=0;i<8;i++){
            int x=dt.x+d[i][0];
            int y=dt.y+d[i][1];
            if(x>0&&y>0&&x<=n&&y<=m){
                if(map[x][y]==-1){
                    map[x][y]=map[dt.x][dt.y]+1;
                    q[head++]={x,y};
                    cnt--;
                }
            }
        }
        tail++;
    }
}
int main(){
    cin>>n>>m;
    int bx,by;
    cin>>bx>>by;
    memset(map,-1,sizeof(map));
    map[bx][by]=0;
    q[head++]={bx,by};
    cnt=n*m-1;
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d",map[i][j]);
        }printf("\n");
    }
    
}