#include<iostream>
#include<algorithm>
using namespace std;
int arr[(int)1.2e4];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    cout<<arr[n/2]<<endl;
}