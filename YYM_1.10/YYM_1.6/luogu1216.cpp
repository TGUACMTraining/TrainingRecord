#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    static int arr[1010][1010];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>arr[i][j];
            arr[i][j]=arr[i][j]+max(arr[i-1][j],arr[i-1][j-1]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,arr[n][i]);
    }
    cout<<ans;
}