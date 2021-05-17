#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
int st_max[(int)5e4+10][30],st_min[(int)5e4+10][30];
inline int p(int k){
    return 1<<k;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        scanf("%d",&st_max[i][0]);
        st_min[i][0]=st_max[i][0];
    }
    for(int j=1;j<30;j++){
        for(int i=1;i-1+p(j)<=n;i++){
            st_max[i][j]=max(st_max[i][j-1],st_max[i+p(j-1)][j-1]);
            st_min[i][j]=min(st_min[i][j-1],st_min[i+p(j-1)][j-1]);
        }
    }
    int l,r,k;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        k=log2(r-l+1);
        r=r+1-p(k);
        cout<<max(st_max[l][k],st_max[r][k])-min(st_min[l][k],st_min[r][k])<<endl;
    }
}