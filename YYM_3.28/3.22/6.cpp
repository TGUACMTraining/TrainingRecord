#include<iostream>
using namespace std;
int arr[40];
void build(){
    arr[0]=3;
    for(int i=1;i<35;i++){
        arr[i]=(arr[i-1]-1)*2;
    }
}
int main(){
    build();
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        cout<<arr[a]<<endl;
    }
}