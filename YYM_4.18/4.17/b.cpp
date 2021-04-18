#include<iostream>
using namespace std;
int gcd(int x,int y){
    if(y==0)return x;
    else return gcd(y,x%y);
}
int main(){
    // int cnt=0;
    // for(int i=1;i<=2020;i++){
    //     for(int j=1;j<=2020;j++){
    //         if(gcd(i,j)==1)cnt++;
    //     }
    // }
    // cout<<cnt<<endl;
    cout<<2481215<<endl;
}