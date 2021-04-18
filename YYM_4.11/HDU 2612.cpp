#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int limit=210;
char map[limit][limit];
int dY[limit][limit];
int dM[limit][limit];
struct dot
{
    int x,y;
}Y,M;
dot q[limit*limit+100];
int head,tail;
int cd[5]={0,1,0,-1,0};
void bfs(int d[][limit]){
    while(head!=tail){
        for(int i=0;i<4;i++){
            int x=q[tail].x+cd[i];
            int y=q[tail].y+cd[i+1];
            if(x>=0&&x<n&&y>=0&&y<m){
                if((map[x][y]=='.'||map[x][y]=='@')&&!d[x][y]){
                    q[head++]={x,y};
                    d[x][y]=d[q[tail].x][q[tail].y]+1;
                }
            }
        }
        tail++;
    }
}
#define clean(x) memset(x,0,sizeof(x))
int main(){
    while(cin>>n>>m)
    {
        clean(dY);
        clean(dM);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>map[i][j];
                if(map[i][j]=='Y')Y={i,j};
                else if(map[i][j]=='M')M={i,j};
            }
        }
        head=tail=0;
        q[head++]=Y;
        bfs(dY);
        head=tail=0;
        q[head++]=M;
        bfs(dM);
        int res=0x3f3f3f3f;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]=='@'){
                    if(dY[i][j]&&dM[i][j])
                        res=min(res,dY[i][j]+dM[i][j]);
                }
            }
        }
        cout<<res*11<<endl;
    }
}