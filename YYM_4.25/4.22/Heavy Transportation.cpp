#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,less<pii> >q;
const int limit=(int)1e3+10;
int dis[limit];
vector<pii> next_[limit];
int poped[limit];
int n;
void dijk(){
    while(!q.empty()){
        int node=q.top().second;
        q.pop();
        if(poped[node])continue;
        poped[node]=1;
        int times=next_[node].size();
        for(int i=0;i<times;i++){
            int trynode=next_[node][i].second;
            int newdis=min(dis[node],next_[node][i].first);
            if(dis[trynode]<newdis){
                dis[trynode]=newdis;
                q.push({newdis,trynode});
            }
        }
    }
}
void cle(){
    memset(dis,0,sizeof(dis));
    for(int i=0;i<limit;i++){
        next_[i].clear();
    }
    memset(poped,0,sizeof(poped));
    priority_queue<pii,vector<pii>,less<pii> >clean;
    swap(clean,q);
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cle();
        int m;
        cin>>n>>m;
        while (m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            next_[u].push_back({w,v});
            next_[v].push_back({w,u});
        }
        dis[1]=0x3f3f3f3f;
        q.push({0x3f3f3f3f,1});
        dijk();
        cout<<"Scenario #"<<i<<":"<<endl;
        cout<<dis[n]<<endl;
    cout<<endl;
    }
}