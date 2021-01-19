#include<iostream>
using namespace std;
unsigned long long fac(int n){
    if(n==0)return (unsigned long long)1;
    else return ((unsigned long long)n)*fac(n-1);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n<8){
            cout<<"Underflow!"<<endl;
        }else if(n>13){
            cout<<"Overflow!"<<endl;
        }else {
            cout<<fac(n)<<endl;
        }
    }
}