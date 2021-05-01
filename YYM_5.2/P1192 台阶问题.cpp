#include<iostream>
using namespace std;
int n,k;
int mod=100003;
int arr[100000+10];
int f(int n){
    if(n<0)return 0;
    if(arr[n])return arr[n];
    for(int i=1;i<=k;i++){
        arr[n]+=f(n-i);
        arr[n]%=mod;
    }
    return arr[n];
}
int main(){
    arr[0]=1;
    cin>>n>>k;
    cout<<f(n);
}