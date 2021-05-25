#include<list>
#include<map>
#include<iostream>
using namespace std;
long long res[1010];
struct item{long long val,cost;};
map<int,list<item>> g;
main(){
    ios::sync_with_stdio(0);
    long long n,m;
    cin>>m>>n;
    for(long long i=1;i<=n;i++){
        item it;
        cin>>it.cost>>it.val;
        int belong;
        cin>>belong;
        g[belong].push_back(it);
    }
    for(auto&gp:g){
        for(long long cst=m;cst>0;cst--)
        for(auto&it:gp.second){
            if(cst>=it.cost)
            res[cst]=max(res[cst],res[cst-it.cost]+it.val);
        }
    }
    cout<<res[m];
}