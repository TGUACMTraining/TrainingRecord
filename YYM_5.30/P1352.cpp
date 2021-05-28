#include<iostream> 
#include<list>
using namespace std;
list<int>child[(int)6e3+10];
bool not_root[(int)6e3+10];
int n;
int happy[(int)6e3+10][2];
bool defined[(int)6e3+10];
void dfs(int root){
    for(int c:child[root]){
        dfs(c);
        happy[root][0]+=max(happy[c][0],happy[c][1]);
        happy[root][1]+=happy[c][0];
    }
    defined[root]=true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&happy[i][1]);
    }
    for(int i=1;i<=n-1;i++){
        int l,k;
        scanf("%d%d",&l,&k);
        child[k].push_back(l);
        not_root[l]=true;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(!not_root[i])root=i;
    }
    dfs(root);
    cout<<max(happy[root][0],happy[root][1]);
}