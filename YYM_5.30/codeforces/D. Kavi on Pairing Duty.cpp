#include<iostream>
using namespace std;
long long MOD=998244353;
long long dp[(int)1e6+10];
int main(){
    int n;
    cin>>n;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            dp[i]+=dp[j];
            dp[i]%=MOD;
        }
    }
    cout<<dp[n]<<endl;
}