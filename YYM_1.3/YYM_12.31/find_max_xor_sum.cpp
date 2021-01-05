#include<bits/stdc++.h>
using namespace std;
const int max_depth=(int)13e5;
const int dig=2;
int tree[max_depth][dig]={0};
int top=0;
void insert_(unsigned int number){
    int length=sizeof(int )*8-1;
    int root=0;
    for(int i=length;i>0;i--){
        int id=(number>>i)&1u;
        if(!tree[root][id])tree[root][id]=++top;
        root=tree[root][id];
    }
}
unsigned int xor_(unsigned int number){
    unsigned int ans=0;
    int length=sizeof(int )*8-1;
    int root=0;
    for(;length>=0;length--){
        int temp=!(number>>length&1u);
        if(tree[root][temp]){root=tree[root][temp];ans|=(1u<<length);}
        else root=tree[root][!temp];
    }
    return ans;
}
int main(){
    int n;
    unsigned int ans=0;
    vector<unsigned int>  cache;
    cin>>n;
    for(int i=0;i<n;i++){
        unsigned int a;
        cin>>a;
        insert_(a);
        cache.push_back(a);
    }
    for(int i=0;i<n;i++){
        unsigned int p;
        ans=ans>(p=xor_(cache[i]))?ans:p;
    }
    cout<<ans<<endl;
    return 0;
}