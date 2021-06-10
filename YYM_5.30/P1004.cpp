#include<iostream>
using namespace std;
int n;
int arr[15][15];
int dp[15][15][15][15];
int main(){
    scanf("%d",&n);
    int x,y,val;
    while(scanf("%d%d%d",&x,&y,&val),x||y||val){
        arr[x][y]=val;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=n;x++){
                for(int y=1;y<=n;y++){
                    #define f(a,b,c,d) dp[i][j][x][y]=max(dp[i][j][x][y],dp[a][b][c][d]);
                    f(i-1,j,x-1,y);
                    f(i,j-1,x-1,y);
                    f(i-1,j,x,y-1);
                    f(i,j-1,x,y-1);
                    if(i==x&&j==y)
                    dp[i][j][x][y]+=arr[i][j];
                    else
                    dp[i][j][x][y]+=arr[i][j]+arr[x][y];
                }
            }
        }
    }
    printf("%d",dp[n][n][n][n]);
}