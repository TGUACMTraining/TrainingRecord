#include<vector>
#include<iostream>
using namespace std;
int n;
const int limit =5e5+10;
char c[limit];
typedef long long ll;
ll ans[limit],ctb[limit];
vector<int>child[limit];
int father[limit];
int stk[limit];
int top;
void dfs(int root){
    int n=0;
    if(c[root]=='('){
        stk[++top]=root;
    }
    else{
        if(top){
            n = stk[top];
            --top;
            ctb[root]=ctb[father[n]]+1;
        }
    }
    ans[root]+=ans[father[root]]+ctb[root];
    for(int x:child[root]){
        dfs(x);
    }
    if(n==0){
        if(top)--top;
    }else if(n){
        stk[++top]=n;
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=2;i<=n;i++){
        int f;
        scanf("%d",&f);
        child[f].push_back(i);
        father[i]=f;
    }
    dfs(1);
    long long res=0;
    for(int i=1;i<=n;i++){
        res^=ans[i]*(long long)i;
    }
    printf("%lld",res);
}