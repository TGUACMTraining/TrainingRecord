#include<iostream>
#include<cmath>
using namespace std;
int n;
int m;
int st[(int)1e6+10][30];
inline int p(int k){
    return 1<<k;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>st[i][0];
    }
    for(int j=1;j<30;j++){
        for(int i=1;i+p(j)-1<=n;i++){
            st[i][j]=min(st[i][j-1],st[i+p(j-1)][j-1]);
        }
    }
    int l=1,r=m;
    while(r<=n){
        int k=log2(r-l+1);
        cout<<min(st[l][k],st[r+1-p(k)][k])<<endl;
        l++;
        r++;
    }
}