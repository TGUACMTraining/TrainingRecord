#include<iostream>
using namespace std;
int highBit(int n){
    if(!n)return 1;
    for(unsigned i=1<<31;1;i>>=1){
        if(n&i)return i;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<highBit(n)-1<<endl;
    }
}