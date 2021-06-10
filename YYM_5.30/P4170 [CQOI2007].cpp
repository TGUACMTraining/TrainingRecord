#include<iostream>
#include<cstring>
using namespace std;
char bord[60];
int n;
int dp[60][60];
bool defined[60][60];
int f(int l,int r){
    if(defined[l][r])return dp[l][r];
    defined[l][r]=true;
    if(l+1==r){return dp[l][r]=(bord[l]==bord[r]?1:2);}
    dp[l][r]=0x3f3f3f3f;
    for(int mid=l;mid<r;mid++){
        dp[l][r]=min(dp[l][r],f(l,mid)+f(mid+1,r)-(bord[l]==bord[r]?1:0));
    }
    return dp[l][r];
} 
int main(){
    scanf("%s",bord+1);
    n=strlen(bord+1);
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
        defined[i][i]=1;
    }
    cout<<f(1,n);
}