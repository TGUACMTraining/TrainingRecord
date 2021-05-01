#include<iostream>
using namespace std;
int arr[1005];
int dfs(int n){
    if(arr[n])return arr[n];
    int ans=1;
    for(int i=1;i<=n/2;i++){
        ans+=dfs(i);
    }
    return arr[n]=ans;
}
int main(){
    int n;
    cin>>n;
    cout<<dfs(n);
}