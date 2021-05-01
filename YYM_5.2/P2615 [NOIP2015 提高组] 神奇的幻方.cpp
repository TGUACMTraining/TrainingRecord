#include<iostream>
using namespace std;
int hf[45][45];
int n;
void dfs(int r,int c,int k){
    if(k==n*n+1)return ;
    if(r==1&&c!=n){r=n;c++;}
    else if(c==n&&r!=1){c=1;r--;}
    else if(r==1&&c==n){r++;}
    else if(r!=1&&c!=n){
        if(!hf[r-1][c+1]){r--,c++;}
        else r++;
    }
    hf[r][c]=k;
    dfs(r,c,k+1);
}
int main(){
    cin>>n;
    hf[1][(n+1)/2]=1;
    dfs(1,(n+1)/2,2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<hf[i][j]<<" ";
        }cout<<endl;
    }
}