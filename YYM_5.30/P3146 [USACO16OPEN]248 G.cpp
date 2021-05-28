#include<iostream>
using namespace std;
int n;
bool dp[300][300][300];
int main(){
    scanf("%d",&n);
    int t;
    register int MAX=0;
    for(register int i=1;i<=n;i++){
        scanf("%d",&t);
        dp[i][i][t]=true;
        MAX=max(MAX,t);
    }
    for(register int len=1;len<=n;len++){
        for(register int l=1,r;(r=l+len-1)<=n;l++){
            for(register int mid=l;mid<r;mid++){
                for(register int i=0;i<=270;i++){
                    if(dp[l][mid][i]&&dp[mid+1][r][i]){
                        dp[l][r][i+1]=true;
                        MAX=max(MAX,i+1);
                    }
                }
            }
        }
    }
    printf("%d",MAX);
}