#include<iostream> 
#include<list>
using namespace std;
int N;
const int limit=2e4+10;
int b[limit];
list<int>child[limit];
int dp[limit][2];
int notRoot[limit];
bool visit[limit];
void dfs(int root){
    visit[root]=true;
    for(int c:child[root]){
        if(visit[c])continue;
        dfs(c);
        dp[root][1]+=max(dp[c][1],0);
        dp[root][0]=max(dp[root][0],max(dp[c][1],dp[c][0]));
    }
}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&dp[i][1]);
    }
    for(int i=2;i<=N;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        child[a].push_back(b);
        child[b].push_back(a);
    }
    dfs(1);
    printf("%d",max(dp[1][0],dp[1][1]));
}