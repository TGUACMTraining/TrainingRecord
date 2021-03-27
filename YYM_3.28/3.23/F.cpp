#include<iostream>
#include<algorithm>
using namespace std;
int arr[(int)1.1e6];

bool xiaoyu(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,xiaoyu);
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}