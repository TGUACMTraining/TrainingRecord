#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<"Today, I ate "<<n;
    if(n==1||n==0){
        cout<<" apple.";
    }else{
        cout<<" apples.";
    }
}