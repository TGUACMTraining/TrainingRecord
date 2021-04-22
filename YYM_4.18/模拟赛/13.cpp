#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int map[105][105];
double dis[105][105];
int poped[105][105];
int n,m;
typedef pair<int,int> dot;
typedef pair<int,dot> p;
priority_queue<p,vector<p>,greater<p> > q;
dot s;
#define x first
#define y second
int cd[8][2]={{0,1},{1,0},{1,1},{-1,0},{-1,-1},{0,-1},{-1,1},{1,-1}};
void dij(){
    q.push({0,s});
    dis[s.x][s.y]=0;
    while(!q.empty()){
        dot now=q.top().second;
        q.pop();
        if(poped[now.x][now.y])continue;
        poped[now.x][now.y]=1;
        for(int i=0;i<8;i++){
            dot next={now.x+cd[i][0],now.y+cd[i][1]};
            if(next.x<0||next.x==n||next.y<0||next.y==m)continue;
            int newdis=dis[now.x][now.y]+(map[now.x][now.y]+map[next.x][next.y])*(i==2||i==4||i==6||i==7?(sqrt(2)-1):1);
            if(newdis<dis[next.x][next.y]){
                dis[next.x][next.y]=newdis;
                q.push({dis[next.x][next.y],next});
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    memset(dis,0x3f,sizeof(dis));
    cin>>s.x>>s.y;
    swap(s.x,s.y);
    dot e;
    cin>>e.y>>e.x;
    dij();
    cout<<dis[e.y][e.x];
}