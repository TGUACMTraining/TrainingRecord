#include<iostream>
using namespace std;
int arr[110][110];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1;i+ans<=n;i++){
        for(int j=1;j+ans<=m;j++){
            while(arr[i-1][j-1]+arr[i+ans][j+ans]-arr[i+ans][j-1]-arr[i-1][j+ans]==(ans+1)*(ans+1))ans++;
        }
    }
    cout<<ans;
}