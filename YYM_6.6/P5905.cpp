#include<queue>
#include<iostream>
#include<vector>
using namespace std;
struct PATH
{
    int vtx;
    int cost;
};
const int limit=3e3+10;
vector<PATH>path[limit];
int h[limit];
int n,m;
bool spfa(int k){
    queue<int>nn;
    int visited[limit]={0};
    bool inqueue[limit]={0};
    memset(h,0x3f,sizeof(h));
    nn.push(k);
    inqueue[k]=true;
    h[k]=0;
    while(!nn.empty()){
        int nd=nn.front();
        nn.pop();
        inqueue[nd]=false;
        for(auto index=path[nd].begin();index!=path[nd].end();index++){
            if(h[index->vtx]>h[nd]+index->cost){
                h[index->vtx]=h[nd]+index->cost;
                if(!inqueue[index->vtx]){
                    inqueue[index->vtx]=true;
                    nn.push(index->vtx);
                    visited[index->vtx]++;
                    if(visited[index->vtx]>n)return false;
                }
            }
        }
    }
    return true;
}
int dis[limit];
struct refresh{
    int node;
    int dis;
    bool operator<(const refresh &a)const{
        return dis>a.dis;
    }
};

void dij(int nd){
    memset(dis,0x3f,sizeof(dis));
    bool poped[limit]={0};
    dis[nd]=0;
    priority_queue<refresh>q;
    q.push({nd,0});
    while(!q.empty()){
        int nn=q.top().node;
        q.pop();
        if(poped[nn])continue;
        poped[nn]=true;
        for(auto index=path[nn].begin();index!=path[nn].end();index++){
            if(dis[index->vtx]>dis[nn]+index->cost){
                dis[index->vtx]=dis[nn]+index->cost;
                q.push({index->vtx,dis[index->vtx]});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        path[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++){
        path[0].push_back({i,0});
    }
    if(!spfa(0))
    {
        printf("-1");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(auto index=path[i].begin();index!=path[i].end();index++){
            index->cost+=h[i]-h[index->vtx];
            cout<<index->cost<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        dij(i);
        long long ans=0;
        for(int j=1;j<=n;j++){
            if(dis[j]>1e9){ans+=j*1e9;}
            else{ans+=j*(dis[j]-h[i]+h[j]);}
        }
        printf("%lld\n",ans);
    }
}