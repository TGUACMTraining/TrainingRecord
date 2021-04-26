#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
const int limit=(int)1e3+10;
vector<pii>ways[limit];
vector<pii>ways_[limit];
int poped[limit];
int dis[limit];
int dis_[limit];
int n,m,x;
void dijk(){
    while (!q.empty())
    {
        int node=q.top().second;
        q.pop();
        if(poped[node])continue;
        poped[node]=1;
        int si=ways[node].size();
        for(int i=0;i<si;i++){
            int tmp=ways[node][i].second;
            int weight=ways[node][i].first;
            if(dis[tmp]>dis[node]+weight){
                dis[tmp]=dis[node]+weight;
                q.push({dis[tmp],tmp});
            }
        }
    }
    
}
void dijk_(){
    while (!q.empty())
    {
        int node=q.top().second;
        q.pop();
        if(poped[node])continue;
        poped[node]=1;
        int si=ways_[node].size();
        for(int i=0;i<si;i++){
            int tmp=ways_[node][i].second;
            int weight=ways_[node][i].first;
            if(dis_[tmp]>dis_[node]+weight){
                dis_[tmp]=dis_[node]+weight;
                q.push({dis_[tmp],tmp});
            }
        }
    }
    
}
void clean(){
    priority_queue<pii,vector<pii>,greater<pii> > emp;
    swap(emp,q);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        ways[a].push_back({c,b});
        ways_[b].push_back({c,a});
    }
    memset(dis,0x3f,sizeof(dis));
    memset(dis_,0x3f,sizeof(dis_));
    dis[x]=0;
    q.push({0,x});
    dijk();
    memset(poped,0,sizeof(poped));
    dis_[x]=0;
    q.push({0,x});
    dijk_();
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dis[i]+dis_[i]);
    }
    cout<<ans<<endl;
}