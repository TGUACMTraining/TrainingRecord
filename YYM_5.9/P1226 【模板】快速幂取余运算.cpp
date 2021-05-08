#include<iostream>
using namespace std;
long long b,p,k;
long long fp(long long b,long long p){
    if(p==0)return 1%k;
    long long res=fp(b%k,p/2);
    res=res*res%k;
    if(p%2)res=res*b%k;
    return res;
}
int main(){
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<fp(b%k,p);
}