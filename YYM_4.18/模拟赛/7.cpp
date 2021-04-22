#include<iostream>
using namespace std;
int mod;
long long fastpow(int i,int j){
    if(j==0)return 1;
    int smaller=fastpow(i,j/2)%mod;
    smaller*=smaller;
    smaller%mod;
    if(j%2)smaller*=i;
    return smaller%mod;
}
int main(){
    cin>>mod;
    int di=0;
    int cache=0;
    do{
        cache+=fastpow(10,di++);
        cache%=mod;
    }while(cache);
    int cache_=0;
    int flag=0;
    for(int i=1;i<=di;i++){
        cache_*=10;
        cache_+=1;
        if(cache_/mod)flag=1;
        if(flag)
        cout<<cache_/mod;
        cache_%=mod;
    }
    cout<<" ";
    cout<<di;
}