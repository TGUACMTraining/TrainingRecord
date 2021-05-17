#include<algorithm>
#include<iostream>
#include<list>
using namespace std;
int n;
const int limit=1e5+10;
int power[limit];
int reset_power[limit];
int ans[limit];
int c[limit];
list<int> child[limit];
int ask(int p){
    int t=0;
    for(int i=p;i;i-=i&-i)t+=c[i];
    return t;
}
void dfs(int node){
    ans[node]-=(ask(n)-ask(power[node]));
    for(int nn:child[node]){
        dfs(nn);
    }
    ans[node]+=(ask(n)-ask(power[node]));
    for(int i=power[node];i<=n;i+=i&-i){
        ++c[i];
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>power[i];
        reset_power[i]=power[i];
    }
    sort(reset_power+1,reset_power+1+n);
    for(int i=1;i<=n;i++){
        power[i]=lower_bound(reset_power+1,reset_power+n+1,power[i])-reset_power;
    }
    for(int i=2;i<=n;i++){
        int father;
        cin>>father;
        child[father].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }

}