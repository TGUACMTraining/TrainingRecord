#include<iostream>
using namespace std;
int main(){
    int  l,r;
    cin>>l>>r;
    r++;
    int cnt=0;
    for(;l<r;l++){
        int n=l;
        while(n){
            if(n%10==2)cnt++;
            n/=10;
        }
    }
    cout<<cnt<<endl;
}