#include<iostream>
using namespace std;
string p,i;
void dfs(int l1,int l2,int r1,int r2)   {
    int root=i.find(p[l2-1]);
    cout<<i[root]<<endl;
    dfs(l1,root+1,r1,root+1);
    dfs(root,l2-1,root+1,r2);

}
int main(){
    cin>>p>>i;
    dfs(0,p.length(),0,i.length());
}