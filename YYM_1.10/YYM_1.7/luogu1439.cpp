#include<bits/stdc++.h>
using namespace std;
const int limit=100010;
int main(){
    int n;
    cin>>n;
    int *arr1;
    int *arr2;
    arr1=new int [n+1]();
    arr2=new int [n+1]();
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }
    static int cache[limit][limit]={0};
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr1[i]==arr2[j])cache[i][j]=cache[i-1][j-1]+1;
            else cache[i][j]=max(cache[i-1][j],cache[i][j-1]);
            if(cache[i][j]>ans)ans=cache[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}