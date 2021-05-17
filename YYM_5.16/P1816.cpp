#include<cmath>
#include<iostream>
using namespace std;
int st[(int)1e5+10][30];
int m,n;
inline int p(int k){
    return 1<<k;
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>st[i][0];
    }
    for(int j=1;j<30;j++){
        for(int i=1;i+p(j)-1<=m;i++){
            st[i][j]=min(st[i][j-1],st[i+p(j-1)][j-1]);
        }
    }
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        int k=log2(r-l+1);
        cout<<min(st[l][k],st[r+1-p(k)][k])<<" ";
    }
}