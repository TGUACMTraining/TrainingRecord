#include<iostream>
using namespace std;
int arr[120];
int add[120];
int main(){
    int n,m;
    int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        add[a]++;
        add[b+1]--;
    }
    for(int i=1;i<=m;i++){
        arr[i]=arr[i-1]+add[i];
        if(!arr[i])cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=m;i++){
        if(!arr[i])cout<<i<<" ";
    }cout<<endl;
}