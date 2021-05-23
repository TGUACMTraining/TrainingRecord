const int limit=1e5+10;
int n,m,arr[limit],ans[limit],tag[limit];
inline int L(int p){return p<<1;}
inline int R(int p){return p<<1|1;}
#define lp L(p)
#define rp R(p)
#define ls lp,l,mid
#define rs rp,mid+1,r
#define mm int mid=(l+r)>>1;
void pushUp(int p){
    ans[p]=ans[lp]+ans[rp];
}
void build(int p,int l,int r){
    if(l==r){
        ans[p]=arr[l];
        return ;
    }
    mm;
    build(ls);
    build(rs);
    pushUp(p);    
}
inline void changeNode(int p,int l,int r,int k){
    ans[p]+=k*(r-l+1);
    tag[p]+=k;
}
inline void pushDown(int p,int l,int r){
    mm;
    changeNode(ls,tag[p]);
    changeNode(rs,tag[p]);
    tag[p]=0;
}
void update(int nl,int nr,int p,int l,int r,int k){
    if(nl<=l&&r<=nr){
        changeNode(p,l,r,k);
        return;
    }
    pushDown(p,l,r);
    mm;
    if(nl<=mid)update(nl,nr,ls,k);
    if(nr>mid)update(nl,nr,rs,k);
    pushUp(p);
}
int query(int al,int ar,int p,int l,int r){
    if(al<=l&&r<=ar)return ans[p];
    int res=0;
    pushDown(p,l,r);
    mm;
    if(al<=mid)res+=query(al,ar,ls);
    if(ar>mid)res+=query(al,ar,rs);
    return res;
}