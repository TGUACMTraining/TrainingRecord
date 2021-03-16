#include<iostream>
using namespace std;
int gcd (int a,int b){
    if(b){
        return gcd(b,a%b);
    }else{
        return a;
    }
}
int main(){
    int m,k;
    while(cin>>m>>k){
        int cache=0;
        while(k){
            cache++;
            if(gcd(cache,m)==1){
                k--;
            }
        }
        cout<<cache<<endl;
    }
}