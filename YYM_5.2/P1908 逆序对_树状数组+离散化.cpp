#include<iostream>
#include<algorithm>
using namespace std;
int n;
// const int limit=10;
const int limit=(int)5e5+100;
int arr[limit];
int c[limit];
long long ans=0;
int main(){
    cin>>n;
    {
        int sorted[limit];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sorted[i]=arr[i];
        }
        sort(sorted,sorted+n);
        for(int i=0;i<n;i++){
            arr[i]=lower_bound(sorted,sorted+n,arr[i])-sorted+1;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    for(int i=n-1;i>=0;i--){
        int j;
        for(j=arr[i]-1;j;j-=j&-j){
            ans+=c[j];
        }
        for(j=arr[i];j<=n;j+=j&-j){
            c[j]++;
        }
    }
    cout<<ans<<endl;
}