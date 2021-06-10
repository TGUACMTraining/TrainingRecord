#include<cstring>
#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;

struct EDGE
{
    int v,w;
    int next;
}e[(int)1e5+10];
int cnt;
int head[(int)3e3+10];
void addedge(int u,int v,int w){
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}

int n,m;
int h[(int)3e3+10];

bool spfa(int k){
    bool inq[(int)3e3+10]={0};
    int vis[(int)3e3+10]={0};
    memset(h,0x3f,sizeof(h));
    queue<int>q;
    
    h[k]=0;
    q.push(k);
    inq[k]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            if(h[v]>h[u]+e[i].w){
                h[v]=h[u]+e[i].w;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                    vis[v]++;
                    if(vis[v]>n)return false;
                }
            }
        }
    }
    return true;
}

struct plan{
    int dis;
    int u;
    bool operator<(plan a)const{
        return dis>a.dis;
    }
};
const int INF=1e9;
int dis[(int)3e3+10];
void dij(int u){
    bool poped[(int)3e3+10]={0};
    for(int i=1;i<=n;i++)dis[i]=INF;
    priority_queue<plan>q;
    dis[u]=0;
    q.push({0,u});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(poped[u])continue;
        poped[u]=true;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                q.push({dis[v],v});
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }

    for(int i=1;i<=n;i++){
        addedge(0,i,0);
    }
    if(!spfa(0)){
        cout<<-1<<endl;
        return 0;
    }
    for(int u=1;u<=n;u++){
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            e[i].w+=h[u]-h[v];
        }
    }
    for(int u=1;u<=n;u++){
        long long ans=0;
        dij(u);
        for(int v=1;v<=n;v++){
            ans+=v*1ll*(dis[v]==INF?INF:(dis[v]-h[u]+h[v]));
        }
        printf("%lld\n",ans);
    }
}