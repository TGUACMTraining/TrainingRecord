#include<vector>
#include<iostream>
using namespace std;
int n;
const int limit =5e5+10;
typedef long long ll;
ll ans[limit],ctb[limit];
char c[limit];
vector<int>child[limit];
int father[limit];
struct 
{
    int stk[limit];
    int tail;
    int top(){
        return stk[tail];
    }
    void push(int n){
        stk[++tail]=n;
    }
    void pop(){--tail;}
}stk;

void dfs(int root){
    int n=0;
    if(c[root]=='('){
        stk.push(root);
    }
    else {
        if(stk.tail){
            n= stk.top();
            stk.pop();
            ctb[root]=ctb[father[n]]+1;
        }
    }
    ans[root]+=ans[father[root]]+ctb[root];
    for(int x:child[root]){
        dfs(x);
    }
    if(n){
        stk.push(n);
    }
    else if(stk.tail)stk.pop();
}
int main(){
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=2;i<=n;i++){
        int k;
        scanf("%d",&k);
        father[i]=k;
        child[k].push_back(i);
    }
    dfs(1);
    long long res=0;
    for(int i=1;i<=n;i++){
        res^=ans[i]*1ll*i;
    }
    printf("%lld",res);
}