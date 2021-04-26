#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    char m;
    int n;
    while(cin>>m){
        m-='a';
        n=m;
        n=a*n+b;
        n%=26;
        n+='a';
        m=n;
        cout<<m;
    }
}