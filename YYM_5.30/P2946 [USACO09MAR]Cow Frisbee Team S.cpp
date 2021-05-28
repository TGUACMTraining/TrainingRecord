#include<iostream>
using namespace  std;
int n,f;
int arr[2000+10];
int dp[2000+10][1000+10];
int MOD=1e8;
int main(){
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        arr[i]%=f;
    }    
    for(int i=1;i<=n;i++){
        ++dp[i][arr[i]];
        for(int j=1;j<=f;j++){
            if(j==f)j=0;
            dp[i][j]+=dp[i-1][j];
            dp[i][j]+=dp[i-1][(j-arr[i]+f)%f];
            dp[i][j]%=MOD;
            if(j==0)j=f;
        }
    }
    printf("%d",dp[n][0]);
}