#include<iostream>
#include<cstdio>
using namespace std;
int MOD;
typedef long long ll;
int key[20000600];
ll fpow(ll a,ll b){
  if(key[a]){return key[a];}
  if(a==0)return 0;
  if(b){
      ll t=fpow(a,b/2)%MOD;
      t=t*t%MOD;
    if(b%2){
      t*=a;
      t%=MOD;
    }
    key[a]=t;
    return key[a];
  }else{return 1;}
}
int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    MOD=p;
    for(int i=1;i<=n;i++){
        printf("%lld\n",fpow(i%p,p-2));
    }
}