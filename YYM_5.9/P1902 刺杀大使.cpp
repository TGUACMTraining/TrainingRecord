#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int maze[1010][1010];
int n,m;
int dire[]={0,1,0,-1,0};
int dis[1010][1010];
bool poped[1010][1010];
typedef int d;
typedef pair<int,int> ver;
typedef pair<d,ver> p;
priority_queue<p,vector<p>,greater<p> >q;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    dis[0][0]=0;
    q.push({0,{0,0}});
    while(!q.empty()){
        ver now=q.top().second;
        q.pop();
        if(poped[now.first][now.second])continue;
        poped[now.first][now.second]=true;
        for(int i=0;i<4;i++){
            int x=+now.first+dire[i];
            int y=+now.second+dire[i+1];
            if(x<0||y<0||x==n||y==m){
                continue;
            }
            if(dis[x][y]>max(dis[now.first][now.second],maze[x][y])){
                dis[x][y]=max(dis[now.first][now.second],maze[x][y]);
                q.push({dis[x][y],{x,y}});
                if(x==n-1)goto flag;
            }
        }
    }flag:
    int ans=0x3f3f3f3f;
    for(int i=0;i<m;i++){
        ans=min(ans,dis[n-1][i]);
    }
    cout<<ans<<endl;
}