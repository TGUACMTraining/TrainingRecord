#include<iostream>
#include<list>
using namespace std;
int n,m,MOD=571373;
const int limit=1e5+10;
int arr[limit];
int ans[limit<<2];
typedef struct {
    int ope;
    int x;
}OPE;
list<OPE> tag[limit<<2];
int inline L(int x) {return x<<1;}
int inline R(int x) {return x<<1|1;}
#define lp L(p)
#define rp R(p)
#define mm int mid=(l+r)>>1;
#define ls lp,l,mid
#define rs rp,mid+1,r
void inline pushUp(int p){
    ans[p]=(ans[lp]+ans[rp])%MOD;
}
void build(int p,int l,int r){
    if(l==r){
        ans[p]=arr[l];
        return;
    }
    mm;
    build(ls);
    build(rs);
    pushUp(p);
}
enum {mul,add};
inline void pushat(int p,int l,int r,OPE &t){
    if(l==r)return;
    if(tag[p].size()){
        OPE &u=(*tag[p].rbegin());
        if(u.ope==t.ope){
            switch (u.ope)
            {
            case mul:
                u.x*=t.x;
                break;
            
            default:
                u.x+=t.x;
                break;
            }
        }else{tag[p].push_back(t);}
    }else{
        tag[p].push_back(t);
    }
}
void inline changeNode(int p,int l,int r,int lastNode){
    for(OPE x:tag[lastNode]){
        pushat(p,l,r,x);
        switch (x.ope)
        {
        case mul:
            ans[p]*=x.x;
            break;
        
        default:
            ans[p]+=(r-l+1)*x.x;
            break;
        }
        ans[p]%=MOD;
    }
}
void inline pushDown(int p,int l,int r){
    mm;
    changeNode(ls,p);
    changeNode(rs,p);
    tag[p].clear();
}

void update(int p,int l,int r,int ul,int ur,int op,int x){
    if(ul<=l&&r<=ur){
        OPE t={op,x};
        pushat(p,l,r,t);
      switch (op)
        {
        case mul:
            ans[p]*=x;
            break;
        
        default:
            ans[p]+=(r-l+1)*x;
            break;
        }
        ans[p]%=MOD;
        return ;
    }
    mm;
    pushDown(p,l,r);
    if(ul<=mid)update(ls,ul,ur,op,x);
    if(mid<ur)update(rs,ul,ur,op,x);
    pushUp(p);
}
int query(int p,int l,int r,int al,int ar){
    if(al<=l&&r<=ar){
        return ans[p];
    }
    int res=0;
    mm;
    pushDown(p,l,r);
    if(al<=mid)res+=query(ls,al,ar);
    if(mid<ar)res+=query(rs,al,ar);
    return res%MOD;
}
void inline r(int &x){
    scanf("%d",&x);
}
string s;
void printTree(int p,int l,int r){
    if(!s.size())cout<<endl;
    mm;
    cout<<s<<"- "<<l<<":"<<r<<":"<<ans[p];
    for(OPE x:tag[p]){
        cout<<" "<<(x.ope?"add ":"mul ")<<x.x;
    }cout<<endl;
    if(l==r){
        cout<<s<<endl;
        return;
    }
    s+="| ";
    printTree(ls);
    printTree(rs);
    s.pop_back();
    s.pop_back();
    if(!s.size())cout<<endl;
}

int main(){
    r(n);r(m);r(MOD);
    for(int i=1;i<=n;i++){
        r(arr[i]);
    }
    build(1,1,n);
    
    // printTree(1,1,n);
    while(m--){
        int o,x,y;
        r(o);r(x);r(y);
        int k;
        switch (o)
        {
        case 1:
            r(k);
            update(1,1,n,x,y,mul,k);
            break;
        case 2:
            r(k);
            update(1,1,n,x,y,add,k);
            break;
        default:
            printf("%d\n",query(1,1,n,x,y));
            break;
        }
        // printTree(1,1,n);

    }
}