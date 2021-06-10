#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int,int> p;
priority_queue<p,vector<p>,greater<p> >q;
const int limit =(int) 1e5+10;
int poped[limit];
vector<p> go[limit];
int dis[limit];
int n,m,s;
void dij(){
    q.push({0,s});
    dis[s]=0;
    while(!q.empty()){
        int now=q.top().second;
        q.pop();
        if(poped[now])continue;
        poped[now]=1;
        for(p next:go[now]){
            if(dis[now]+next.first<dis[next.second]){
                dis[next.second]=dis[now]+next.first;
                q.push({dis[next.second],next.second});
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        go[u].push_back({w,v});
    }
    memset(dis,0x3f,sizeof(dis));
    dij();
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }cout<<endl;
}