#include<iostream>
using namespace std;
int grid[400];
int n;
int dp[45][45][45][45];
bool defined[45][45][45][45];
#define change(x,y,z,w) dp[a][b][c][d]=max(dp[a][b][c][d],f(x,y,z,w))  
int f(int a,int b,int c,int d){
    if(defined[a][b][c][d])return dp[a][b][c][d];
    defined[a][b][c][d]=true;
    if(a>0)
    change(a-1,b,c,d);
    if(b>0)
    change(a,b-1,c,d);
    if(c>0)
    change(a,b,c-1,d);
    if(d>0)
    change(a,b,c,d-1);
    return dp[a][b][c][d]+=grid[1+a+b*2+c*3+d*4];
}
int main(){
    int dx[5]={0};
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",grid+i);
    }
    for(int i=0;i<m;i++){
        int cache;
        scanf("%d",&cache);
        ++dx[cache];
    }
    printf("%d",f(dx[1],dx[2],dx[3],dx[4]));
}