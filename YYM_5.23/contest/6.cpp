#include<iostream>
#include<list>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,k;
const  int limit=1e5+10;
int r[limit];
int visited[limit];
int used[limit];
double w[limit];
int zero[limit];
list<pair<int,int> >child[limit];
int tail;
bool jud(double w1,int r1,int changeNode){
    if(zero[changeNode]==0){
        w[changeNode]=-w1*r1/r[changeNode];
        return true;
    }
    else{
        if(fabs(w1*r1+w[changeNode]*r[changeNode])<5.5e-6)return true;
        else return false;
    }
}
int ERR=0;
void dfs(int node){
    visited[node]=1;
    if(ERR==1)return;
    for(auto ind:child[node]){
        if(used[ind.second]){continue;}
        used[ind.second]=1;
        if(!jud(w[node],r[node],ind.first)){
            ERR=1;
        }
        dfs(ind.first);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
    }
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        child[l].push_back({r,m+1});
        child[r].push_back({l,m+1});
    }
    memset(zero,1,sizeof(zero));
    while(k--){
        int node;
        scanf("%d",&node);
        zero[node]=0;
        scanf("%lf",&w[node]);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]&&ERR==0&&zero[i]==0)
        dfs(i);
    }
    if(ERR){
        printf("It is not steampunk!");
        return 0;
    }
    
    for(int i=1;i<=n;i++){
        if((!visited[i])&&ERR==0){
            w[i]=102;
            dfs(i);
        }
    }
    if(ERR){
        printf("Steampunk!\n");
        for(int i=1;i<=n;i++){
            if(zero[i]){
                printf("0.0000 ");
            }else{
                printf("%.4lf ",w[i]);
            }
        }
    }else{
        printf("oo");
    }
}