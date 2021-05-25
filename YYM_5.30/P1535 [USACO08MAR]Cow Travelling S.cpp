#include<iostream>
using namespace std;
int cd[]={0,1,0,-1,0};
int n,m,T;
int map[110][110];
int des[2];

int dfs(int x,int y,int t){
    if(t==T){
        if(x==des[0]&&y==des[1]){
            return 1;
        }else{
            return 0;
        }
    }
    int res=0;
    if(abs(x-des[0])+abs(y-des[1])<=T-t)
    for(int i=0;i<4;i++){
        int xx=(x+cd[i]),yy=(y+cd[i+1]);
        if(xx>0&&xx<=n&&yy>0&&yy<=m&&map[xx][yy]==0)
        res+=dfs(xx,yy,t+1);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>T;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='*')map[i][j]=1;
        }
    }
    int x,y;
    cin>>x>>y>>des[0]>>des[1];
    cout<<dfs(x,y,0);
}