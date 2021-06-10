#include <iostream>
#include <list>
using namespace std;
list<int> child[310];
int val[310];
bool notroot[310];
int ans[310];
int n, m;
void merge(int a[],int b[],int at[]){
    int c[310]={0};
    for(int i=1;i<=m;i++){
        for(int j=0;j<=i;j++){
            c[i]=max(c[i],a[j]+b[i-j]);
        }
    }
    for(int i=1;i<=m;i++){
        at[i]=c[i];
    }
}
void query(int root,int arr_father[]){
    int arr_child[310]={0};
    for(int c:child[root]){
        int this_child[310]={0};
        query(c,this_child);
        merge(arr_child,this_child,arr_child);
    }
    for(int i=m;i>0;i--){
        arr_father[i]=arr_child[i-1]+val[root];
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; i++) {
        int value, father;
        scanf("%d%d", &father, &value);
        val[i] = value;
        if (father != 0) {
            child[father].push_back(i);
            notroot[i] = true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!notroot[i]){
            int this_tree[310]={0};
            query(i,this_tree);
            merge(ans,this_tree,ans);
        }
    }
    printf("%d", ans[m]);
}