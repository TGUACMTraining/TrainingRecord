#include<iostream>
using namespace std;
int n,m,k;
long long arr[2][210][210][2];
const int MOD=1000000007;
char a[1010],b[210];
inline long long & dp(int i,int j,int k,int mode){
    return arr[i&1][j][k][mode];
}
int main(){
    scanf("%d%d%d%s%s",&n,&m,&k,a+1,b+1);
    dp(0,0,0,0)=dp(1,0,0,0)=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int kk=1;kk<=k;kk++){
                if(a[i]==b[j]){
                    dp(i,j,kk,1)=((dp(i-1,j-1,kk,1)+dp(i-1,j-1,kk-1,1))%MOD+dp(i-1,j-1,kk-1,0))%MOD;
                    dp(i,j,kk,0)=(dp(i-1,j,kk,0)+dp(i-1,j,kk,1))%MOD;
                }else {
                    dp(i,j,kk,0)=(dp(i-1,j,kk,0)+dp(i-1,j,kk,1))%MOD;
                    dp(i,j,kk,1)=0;
                }
            }
        }
    }
    printf("%lld",(dp(n,m,k,0)+dp(n,m,k,1))%MOD);
    return 0;
}