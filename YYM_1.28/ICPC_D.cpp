#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[30][30];
int main(){
    int n;
    cin>>n;
    int cache;
    int *arr=new int [n+1];
    for(int i=1;i<=n;i++){
        cin>>cache;
        arr[cache]=i;
    }
    int *compare=new int [n+1];
    while(!(cin>>cache).eof()){
        compare[cache]=1;
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=n;i++){
            cin>>cache;
            compare[cache]=i;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(compare[j]==arr[i])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                ans=max(dp[i][j],ans);
            }
        }
        cout<<ans<<endl;
    }
    
}