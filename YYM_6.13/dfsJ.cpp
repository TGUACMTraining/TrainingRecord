#include<iostream>
using namespace std;
const int limit=1e5+10;
int stk[limit][3];
struct{
    int v;
    int next;
}child[limit*2];
int head[limit];
int cnt;
void add_edge(int u,int v){
    child[++cnt].v=v;
    child[cnt].next=head[u];
    head[u]=cnt;
}
bool visited[limit];
void dfs(int t){
    printf("%d ",t);
    for(int i=head[t];i;i=child[i].next){
        if(!visited[child[i].v]){
            visited[child[i].v]=true;
            dfs(child[i].v);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(stk,0,sizeof(stk));
        memset(child,0,sizeof(child));
        memset(head,0,sizeof(head));
        memset(visited,0,sizeof(visited));
        cnt=0;
        int n;
        int m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            stk[i][0]=i;
            stk[i][1]=i;
            stk[i][2]=1;
        }
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(stk[x][2]==0)continue;
            if(stk[y][2]==0){
                stk[y][1]=stk[x][0];
                stk[y][0]=stk[x][1];
                stk[y][2]=stk[x][2];
                stk[x][2]=stk[x][0]=stk[x][1]=0;
                continue;
            }
            add_edge(stk[x][1],stk[y][1]);
            add_edge(stk[y][1],stk[x][1]);
            stk[y][2]+=stk[x][2];
            stk[y][1]=stk[x][0];
            stk[x][2]=stk[x][0]=stk[x][1]=0;
        }
        for(int i=1;i<=n;i++){
            printf("%d ",stk[i][2]);
            if(stk[i][2]){
            visited[stk[i][1]]=true;
            dfs(stk[i][1]);
            }
            printf("\n");
        }
    }
}