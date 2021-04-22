#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
typedef int vertax;
typedef int d;
typedef pair<d,vertax> p;
priority_queue<p,vector<p>,greater<p> >q;
int n,m,s;
vector<p> e[(int)1e5+10];
int dis[(int)1e5+10];
int vis[(int)1e5+10];
void dijk(){
    q.push({0,s});
    dis[s]=0;
    while(!q.empty()){
        int now=q.top().second;
        q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(p i:e[now]){
            if(dis[i.second]>dis[now]+i.first){
                dis[i.second]=dis[now]+i.first;
                q.push({dis[i.second],i.second});
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({w,v});
    }
    memset(dis,0x3f,sizeof(dis));
    dijk();
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }return 0;
}