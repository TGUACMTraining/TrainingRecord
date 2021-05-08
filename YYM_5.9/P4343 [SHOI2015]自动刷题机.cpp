#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;
int line,k;
const int lim=(int)1e5+10;
ll difCodelen[lim];
ll ac(ll t){
    ll codelen=0;
    ll ans=0;
    for(int i=1;i<=line;i++){
        codelen+=difCodelen[i];
        if(codelen<0){codelen=0;}
        if(codelen>=t){codelen=0;ans++;}
    }
    return ans;
}
ll lower(ll l,ll r){
    while(l<r){  
        ll mid=(l+r)>>1;
        if(ac(mid)>k){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return l;
}
ll upper(ll l,ll r){
    while(l<r){
        ll mid=(l+r+1)/2;
        if(ac(mid)<k){
            r=mid-1;
        }else{
            l=mid;
        }
    }
    return l;
}
int main(){
    cin>>line>>k;
    ll l=1, r=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=line;i++){
        cin>>difCodelen[i];
    }
    ll low,up;
    low=lower(l,r);
    up=upper(l,r);
    // cout<<ac(0)<<endl;
    if(ac(low)==k&&ac(up)==k){
        cout<<low<<" "<<up<<endl;
    }else{
        cout<<-1<<endl;
    }
}