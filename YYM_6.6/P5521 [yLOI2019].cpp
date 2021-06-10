#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int node_lim=1e5+10;
int n;
int w[node_lim];
int cost[node_lim];
vector<int>child[node_lim];
int dfs(int d){
    if(cost[d])return cost[d];
    int cc=0;//current cost
    int ans=0;
    for(int x:child[d]){
        dfs(x);
    }
    auto cmp=[](int a,int b)->bool{
        return cost[a]-w[a]>cost[b]-w[b];
    };
    sort(child[d].begin(),child[d].end(),cmp);
    for(int x:child[d]){
        ans=max(ans,cc+dfs(x));
        cc+=w[x];
    }
    cc+=w[d];
    ans=max(ans,cc);
    return cost[d]=ans;
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int f;
        scanf("%d",&f);
        child[f].push_back(i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",w+i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        printf("%d ",cost[i]);
    }
}