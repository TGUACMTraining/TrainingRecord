#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n;
ll arr[50010];
char *p;
inline void read(register ll &x){
    x=0;
    while(!isdigit(*p))++p;
    while(isdigit(*p))x=x*10+(*p++&15);
}
int main(){
    p=new char [(int)1e8];
    fread(p,1,(int)1e8,stdin);
    read(n);
    for(ll i=1;i<=n;i++){
        read(arr[i]);
        arr[i]+=arr[i-1];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=n-i;j>=ans;j--){
            if((arr[j+i]-arr[i-1])%7==0){
                ans=max(ans,j+1);
            }
        }
    }
    printf("%lld",ans);
}