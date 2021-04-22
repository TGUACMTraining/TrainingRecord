#include<iostream>
#include<string>
using namespace std;
void dfs(string p,string i){
    if(p.size()<=0)return;
    int root=i.find(p[0]);
    dfs(p.substr(1,root),i.substr(0,root));
    dfs(p.substr(root+1),i.substr(root+1));
    cout<<p[0];
}
int main(){
    string p,i;
    while(cin>>p>>i){
        dfs(p,i);
        cout<<endl;
    }
}