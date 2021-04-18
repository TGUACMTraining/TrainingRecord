#include<iostream>
#include<algorithm>
using namespace std;
bool ls(const int a,const int b){
    return a%2>b%2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[2100];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,ls);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
}