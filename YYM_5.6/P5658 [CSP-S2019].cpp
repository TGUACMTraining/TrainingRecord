#include <iostream>
#include <vector>
using namespace std;
const int limit = 5e5 + 10;
long long ctb[limit], ans[limit];
vector<int> child[limit];
int father[limit];
char c[limit];
int n;
struct 
{
    int stk[limit];
    int tail=0;
    void pop(){
        --tail;
    }
    void push(int i){
        stk[++tail]=i;
    }
    int top(){
        return stk[tail];
    }
}stk;

void dfs(int root)
{
	int n=0;
    if(c[root]=='('){
    	stk.push(root);
    }
	else{
		if(stk.tail){
			n=stk.top();
			ctb[root]=ctb[father[n]]+1;
			stk.pop();
		}
	}
	ans[root]+=ans[father[root]]+ctb[root];
    for (int x : child[root]) {
        dfs(x);
    }
	if(n!=0)stk.push(n);
	else if(stk.tail)stk.pop();
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c[i]);
    }
    for (int i = 2; i <= n; i++) {
        int cache;
        scanf("%d", &cache);
        father[i]=cache;
        child[cache].push_back(i);
    }
    dfs(1);
	long long res=0;
	for(int i=1;i<=n;i++){
		res^=ans[i]*(long long)i;
	}
	printf("%lld",res);
}