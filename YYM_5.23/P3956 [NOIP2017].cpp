#include<iostream>
#include<cstring>
using namespace std;
int map[105][105];
int costs[105][105];
int m,n;
enum {yellow=1,red};
int nd[]={0,1,0,-1,0};
int ans=1e9;
void printMap(){
    cout<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]==red)cout<<"red ";
            else if(map[i][j]==yellow) cout<<"yel ";
            else if(map[i][j]==0)cout<<"whi ";
        }cout<<endl;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(costs[i][j]<1e4){
                printf("%-4d",costs[i][j]);
            }else{
                cout<<"udf ";
            }
        }cout<<endl;
    }cout<<endl;
}
void dfs(int x_,int y_,int color,int cost){
    if(x_==m&&y_==m){
        return ;
    }
    for(int i=0;i<4;i++){
        int x=x_+nd[i];
        int y=y_+nd[i+1];
        if(x>0&&x<=m&&y>0&&y<=m){
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
            costs[x][y]=ncost;
            dfs(x,y,ncolor,ncost);
        }
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        if(!c)c=red;
        else c=yellow;
        map[x][y]=c;
    }
    memset(costs,0x3f,sizeof(costs));
    costs[1][1]=0;
    dfs(1,1,map[1][1],0);
    if(costs[m][m]>1e6)cout<<-1<<endl;
    else
    cout<<costs[m][m]<<endl;
}