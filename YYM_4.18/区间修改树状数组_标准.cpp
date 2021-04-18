#include<iostream>
using namespace std;
typedef long long ll;
const int limit=(int)5e5;
ll sum1[limit]={0};
ll sum2[limit]={0};
int n=10;
void add(ll p,ll x){
    for(int i=p;i<=n;i+=i&-i)
        sum1[i]+=x,sum2[i]+=x*p;
}
void range_add(ll l, ll r, ll x){
    add(l,x), add(r+1,-x);
}
ll ask(ll p){
    ll res=0;
    for(int i=p;i;i-=i&-i)
        res+=(p+1)*sum1[i]-sum2[i];
    return res;
}
ll range_ask(ll l, ll r){
    return ask(r)-ask(l-1);
}
int main(){
    range_add(1,10,1);
    cout<<ask(10);
}