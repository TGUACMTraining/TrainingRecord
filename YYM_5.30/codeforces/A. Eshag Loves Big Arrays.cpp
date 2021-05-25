#include<iostream>
#include<algorithm>
using namespace std;
int arr[200];

int n;
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<arr+n-upper_bound(arr,arr+n,arr[0])<<endl;
    }
}