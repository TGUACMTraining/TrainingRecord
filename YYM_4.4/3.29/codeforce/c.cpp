#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
const int limit=1010;
int mod=1e9+7;
int arr[limit][limit];
int result[limit][limit];
int build(int n,int k){
    memset(arr,0,sizeof(arr));
    arr[1][0]=1;
    result[1][k]=1;
    result[2][k]=1;
    for(int i=1;i<=k;i++){
        arr[2][i]=1;
        result[2][k]=(arr[2][i]+result[2][k])%mod;
    }
    for(int i=3;i<=n;i++){
        switch (i%2)
        {
        case 0:
            arr[i][1]=0;
            result[i][k]=result[i-1][k];
            for(int j=2;j<=k;j++){
                arr[i][j]=(arr[i][j-1]+arr[i-1][j-1])%mod;
                result[i][k]=(result[i][k]+arr[i][j])%mod;
            }
            break;
        
        case 1:
            arr[i][k]=0;
            result[i][k]=result[i-1][k];
            for(int j=k;j>0;j--){
                arr[i][j]=(arr[i][j+1]+arr[i-1][j+1])%mod;
                result[i][k]=(result[i][k]+arr[i][j])%mod;
            }
            break;
        }
    }
    return result[n][k];
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<build(k,n)<<endl;
    }


}
/*
1 1 1 1 1
4 3 2 1 0
0 4 7 9 10
*/