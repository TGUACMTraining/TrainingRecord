#include<iostream> 
using namespace std;
const int MAX=2e5+10;
int n,m,ans[MAX<<2],tag[MAX<<2];
inline int L(int p){
    return p<<1;
}
inline int R(int p){
    return p<<1|1;
}
#define lp L(p)
#define rp R(p)
#define mm int mid=(l+r)>>1;
void pushUp(int p){
    ans[p]=ans[lp]+ans[rp];
}
void changeNode(int p,int l,int r){
    ans[p]=(r-l+1-ans[p]);
    tag[p]=!tag[p];
}
void pushDown(int p,int l,int r){
    mm;
    if(tag[p]){
        changeNode(lp,l,mid);
        changeNode(rp,mid+1,r);
        tag[p]=0;
    }
}
void update(int nl,int nr,int l,int r,int p){
    if(nl<=l&&r<=nr){
        changeNode(p,l,r);
        return ;
    }
    mm;
    pushDown(p,l,r);
    if(nl<=mid)update(nl,nr,l,mid,lp);
    if(mid<nr)update(nl,nr,mid+1,r,rp);
    pushUp(p);
}
int query(int l,int r,int p,int al,int ar){
    if(al<=l&&r<=ar)return ans[p];
    mm;
    pushDown(p,l,r);
    int res=0;
    if(al<=mid)res+=query(l,mid,lp,al,ar);
    if(ar>mid)res+=query(mid+1,r,rp,al,ar);
    return res;
}
void r(int &x){
    scanf("%d",&x);
}

int main(){
    int c,a,b;
    r(n);r(m);
    while(m--){
        r(c);r(a);r(b);
        switch (c)
        {
        case 0:
            update(a,b,1,n,1);

            break;
        
        default:
            printf("%d",query(1,n,1,a,b));

            break;
        }
    }
}