#include<iostream>
#include<cstring>
using namespace std;
struct NODE{
    int father;
    int cost;
}node[(int)1e5+10];//root:1
int n;
bool visited[(int)1e5+10];
int val[(int)1e5+10];
int find_father(int d){
    visited[d]=true;
    if(node[d].father==d)return 0;
    return val[d]=find_father(node[d].father)+node[d].cost;
}
int dis_(int n){
    int f=n;
    int va=0;
    while(!visited[f]){
        va+=node[f].cost;
        f=node[f].father;
    }return va-val[f];
}
int dis(int from,int to){
    return dis_(to)+val[from];
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,v;
        cin>>a>>b>>v;
        if(a>b)swap(a,b);//a<b
        node[b].father=a;
        node[b].cost=v;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        find_father(i);
        for(int j=i+1;j<=n;j++){
            cout<<dis_(j)<<endl;
            int cache=dis(i,j);
            cout<<i<<":"<<j<<":"<<cache<<endl;
            ans+=cache*cache;
        }
    }
    cout<<ans<<endl;
}
/*
7
1 2 1
2 3 9
2 4 2
3 5 4
5 6 2
5 7 6
*/