#include<iostream>
using namespace std;
int a[(int)1e5+10];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        a[i]=a[i]-a[i-1];
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<a[i]<<endl;
    }
}