#include<iostream>
using namespace std;
#define int long long
const int limit=1e5+10;
int n,m,MOD;
int arr[limit],ans[limit<<2];
struct  lazyTag{
    int mul;
    int add;
    void init(){
        mul=1;
        add=0;
    }
    lazyTag(){init();}
    void Merge(lazyTag m){
        mul*=m.mul;
        add=add*m.mul+m.add;
        mul%=MOD;
        add%=MOD;
    }
}tag[limit<<2];

void inline read(int &x){
    scanf("%lld",&x);
}
void inline pr(long long x){printf("%lld ",x);}
int inline L(int t){return t<<1;}
int inline R(int t){return t<<1|1;}
#define lp L(p)
#define rp R(p)
#define mm int mid=(l+r)>>1;
#define ls lp,l,mid
#define rs rp,mid+1,r
void inline pushUp(int p){
    ans[p]=ans[lp]+ans[rp];
    ans[p]%=MOD;
}
void build(int p,int l,int r){
    if(l==r){ans[p]=arr[l];return;}
    mm;
    build(ls);
    build(rs);
    pushUp(p);
}
void inline changeNode(int lastNode,int p,int l,int r){
    ans[p]=ans[p]*tag[lastNode].mul+tag[lastNode].add*(r-l+1);
    ans[p]%=MOD;
    tag[p].Merge(tag[lastNode]);
}
void inline pushDown(int p,int l,int r){
    mm;
    changeNode(p,ls);
    changeNode(p,rs);
    tag[p].init();
}
enum{emul,eadd};
void update(int ul,int ur,int op,int x,int p,int l,int r){
    if(ul<=l&&r<=ur){
        tag[0].init();
        switch (op)
        {
        case emul:
            tag[0].mul*=x;
            break;
        
        case eadd:
            tag[0].add+=x;
            break;
        }
        changeNode(0,p,l,r);
        return;
    }
    mm;
    pushDown(p,l,r);
    if(ul<=mid){update(ul,ur,op,x,ls);}
    if(mid<ur){update(ul,ur,op,x,rs);}
    pushUp(p);
}
long long query(int al,int ar,int p,int l,int r){
    if(al<=l&&r<=ar){
        return ans[p];
    }
    mm;
    long long ans=0;
    pushDown(p,l,r);
    if(al<=mid)ans+=query(al,ar,ls);
    if(mid<ar)ans+=query(al,ar,rs);
    return ans%MOD;
}
string s;
void printTree(int p,int l,int r){

    if(l==r){cout<<s<<endl;}
    cout<<s<<"--"<<l<<":"<<r<<":"<<ans[p]<<" "<<tag[p].add<<":"<<tag[p].mul<<endl;
    if(l==r){return;}
    s+="  |";
    mm;
    printTree(ls);
    printTree(rs);
    s.pop_back();
    s.pop_back();
    s.pop_back();
}
main(){
    read(n);
    read(m);
    read(MOD);
    for(register int i=1;i<=n;++i){
        read(arr[i]);
    }
    build(1,1,n);
    // printTree(1,1,n);
    while(m--){
        int op,x,y,k;
        read(op);
        read(x);read(y);
        if(op!=3)
        read(k);
        if(op==3){
            pr(query(x,y,1,1,n));
            printf("\n");
        }
        switch (op)
        {
        case 1 :
            update(x,y,emul,k,1,1,n);
            break;
        
        case 2 :
            update(x,y,eadd,k,1,1,n);
            break;
        }
        // printTree(1,1,n);
    }

}