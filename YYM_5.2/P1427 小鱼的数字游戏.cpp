#include<iostream>
using namespace std;
int arr[110];
int tail;
int main(){
    int cache;
    while(cin>>cache,cache){
        arr[tail++]=cache;
    }
    for(int i=tail-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}