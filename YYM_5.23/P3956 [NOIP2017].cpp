#include<iostream>
using namespace std;
int map[105][105];
int visited[105][105];
int costs[105][105];
int m,n;
enum {yellow=1,red};
int nd[]={0,1,0,-1,0};
int ans=1e9;
void dfs(int x_,int y_,int color,int cost){
    if(x_==m&&y_==m){
        return ;
    }
    costs[x_][y_]=cost;
    for(int i=0;i<4;i++){
        int x=x_+nd[i];
        int y=y_+nd[i+1];
        if(x>0&&x<=m&&y>0&&y<=m&&visited[x][y]==0){
            int ncolor,ncost;
            if(map[x_][y_]==0){
                if(map[x][y]){
                    ncolor=map[x][y];
                    ncost=(ncolor==color?0:1)+cost;
                }else{continue;}
            }else{
                if(map[x][y]==0){ncolor=color;ncost=2;}
                else {ncolor=map[x][y];ncost=(ncolor==color?0:1);}
                ncost+=cost;
            }
            if(ncost>=costs[x][y])continue;    
            visited[x][y]=1;
            dfs(x,y,ncolor,cost+ncost);
            visited[x][y]=0;
        }
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        if(!c)c=red;
        map[x][y]=c;
    }
    memset(costs,0x3f,sizeof(costs));

    dfs(1,1,map[1][1],0);
}