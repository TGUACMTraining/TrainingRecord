#include<algorithm>
#include<iostream>
using namespace std;
// #define dbg(x) {x;}
#define dbg(x)
int n,q;
const int limit=1e5+10;
int father[limit];
int ss[limit];//size of set
int ff(int k){//find father
    int r=k;
    while(r!=father[r]){
        r=father[r];
    }
    while(k!=r){
        int cache=father[k];
        father[k]=r;
        k=cache;
    }
    return r;
}
inline void uni(int a,int b){
    if(ff(a)!=ff(b)){
        ss[ff(b)]+=ss[ff(a)];
        ss[ff(a)]=0;
        father[ff(a)]=ff(b);
    }
}
inline int as(int k){//ask size
    return ss[ff(k)];
}
struct EDGE{
    int a,b;
    int value;
}e[limit];
int ei[limit];//edge index
int ee;
struct ASK
{
    int val,node,order,ans;
}ask[limit];
int al,ar;

int main(){
    for(int i=0;i<limit;i++){
        father[i]=i;
        ss[i]=1;
        ei[i]=i;
        ask[i].order=i;
    }
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        dbg(cout<<"edge:";)
        cin>>e[i].a>>e[i].b>>e[i].value;
    }
    {
        auto cmp=[](int a,int b)->bool{
            return e[a].value>e[b].value;
        };
        sort(ei,ei+n-1,cmp);
    }
    for(int i=0;i<q;i++){
        dbg(cout<<"ask:";)
        cin>>ask[i].val>>ask[i].node;
    }
    {
        auto cmp=[](ASK a,ASK b)->bool{
            return a.val>b.val;
        };
        sort(ask,ask+q,cmp);
    }
    dbg(
        cout<<"after sort:"<<endl;
        cout<<"edge:"<<endl;
        for(int i=0;i<n-1;i++){
            cout<<e[ei[i]].a<<" "<<e[ei[i]].b<<" "<<e[ei[i]].value<<endl;
        }cout<<endl;
        cout<<"ask:"<<endl;
        for(int i=0;i<q;i++){
            printf("%d %d %d\n",ask[i].val,ask[i].node,ask[i].order);
        }cout<<endl;
    )
    {
        auto ca=[](ASK a,ASK b)->bool{
            return a.val>b.val;
        };
        while(al!=q){
            ar=upper_bound(ask,ask+q,ask[al],ca)-ask;
            dbg(printf("bigger than: %d \n",ask[al].val);)
            while(ee!=n-1&&e[ei[ee]].value>=ask[al].val){
                uni(e[ei[ee]].a,e[ei[ee]].b);
                dbg(printf("union : %d %d\n",e[ei[ee]].a,e[ei[ee]].b);)
                dbg(for(int i=1;i<=n;i++){cout<<i<<":"<<father[i]<<":"<<ss[i]<<"\t";}cout<<endl;)
                ee++;
            }
            for(int i=al;i<ar;i++){
                ask[i].ans=as(ask[i].node);
            }
            al=ar;
        }
    }
    {
        auto ca=[](ASK a,ASK b)->bool{
            return a.order<b.order;
        };
        sort(ask,ask+q,ca);
        for(int i=0;i<q;i++){
            cout<<ask[i].ans-1<<endl;
        }
    }
}