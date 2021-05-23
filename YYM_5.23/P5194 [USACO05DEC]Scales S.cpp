#include<iostream>
using namespace std;
const int limit=1005;
int weight[limit];
int sum[limit];
int ans;
int n,c;
int visited[limit];
void dfs(int node,int w){
    ans=max(ans,w);
    if(w+sum[node+1]<ans)return;
    for(int i=node+1;i<n;i++){
        if(!visited[i]){
            if(c-w-weight[i]>=0){
                visited[i]=1;
                dfs(i,w+weight[i]);
                visited[i]=0;
            }
        }
    }
}
int main(){
    cin>>n>>c;
    for(int i=n-1;i>=0;i--){
        cin>>weight[i];
    }
    for(int i=n-1;i>=0;i--){
        sum[i]=sum[i+1]+weight[i];
    }
    for(int i=0;i<n;i++){
        visited[i]=1;
        if(c-weight[i]>=0)
        dfs(i,weight[i]);
        visited[i]=0;
    }
    cout<<ans;
}