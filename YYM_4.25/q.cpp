#include<iostream>
using namespace std;
int tail=0;
const int limit=20;
int lc[limit];
int rc[limit];
int mode;
void traverse(int root){
    if(root==0)return ;
    if(mode==1){cout<<root<<" ";}
    traverse(lc[root]);
    traverse(rc[root]);
    if(mode==3){cout<<root<<" ";}
}
int main(){
    int f,l,r;
    int n;
    cin>>n;
    while(cin>>f>>l>>r,n--){
        lc[f]=l;
        rc[f]=r;
    }
    int root;
    cin>>root;
    mode=1;
    traverse(root);
    cout<<endl;
    mode=3;
    traverse(root);
}