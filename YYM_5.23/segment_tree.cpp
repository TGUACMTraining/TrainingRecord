#include<iostream>
using namespace std;
#define ll long long
const int MAX=1e5+10;
ll n,m,a[MAX],ans[MAX<<2],tag[MAX<<2];
ll inline L(int p){return p<<1;}
ll inline R(int p){return p<<1|1;}
#define lp L(p)
#define rp R(p)
#define mm ll mid=(l+r)>>1;
void pushUp(int p){
    ans[p]=ans[lp]+ans[rp];
}
void build(int p,int l,int r){
    tag[p]=0;
    if(l==r){
        ans[p]=a[l];
        return ;
    }
    mm
    build(lp,l,mid);
    build(rp,mid+1,r);
    pushUp(p);
}
void inline changeNode(int p,int l,int r,int k){
    ans[p]+=k*(r-l+1);
    tag[p]+=k;
}
void inline pushDown(int p,int l,int r){
    mm ;
    changeNode(lp,l,mid,tag[p]);
    changeNode(rp,mid+1,r,tag[p]);
    tag[p]=0;
}
void update(int nl,int nr,int l,int r,int p,int k){
    if(nl<=l&&r<=nr){
        changeNode(p,l,r,k);
        return ;
    }
    mm;
    if(l<=mid){
        update(nl,nr,l,mid,lp,k);
    }
    if(r>mid){
        update(nl,nr,mid+1,r,rp,k);
    }
    pushUp(p);
}
ll query(int al,int ar,int l,int r,int p){
    if(al<=l&&r<=ar)return ans[p];
    mm;
    ll res=0;
    pushDown(p,l,r);
    if(l<=mid)res+=query(al,ar,l,mid,lp);
    if(r>mid)res+=query(al,ar,mid+1,r,rp);
    return res;
}

int main(){

}