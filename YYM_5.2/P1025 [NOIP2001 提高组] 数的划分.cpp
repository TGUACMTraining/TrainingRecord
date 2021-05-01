#include<iostream>
using namespace std;
int arr[210][10][210];
int dfs(int n,int k,int ma){
    if(k==0&&n==0){return 1;}
    if(k==0||n==0)return 0;
    if(arr[n][k][ma])return arr[n][k][ma];
    int ans=0;
    for(int i=ma;i>0;i--){
        if(n-i>=0){
            ans+=dfs(n-i,k-1,i);
        }        
    }
    return arr[n][k][ma]=ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<dfs(n,k,n)<<endl;
}