#include<iostream>
using namespace std;
int main(){
    int n0,n1;
    n0=1;
    n1=1;
    int n;
    cin>>n;
    int cnt=1;
    while(!(n0==0&&n1==1)){
        int n2=n0+n1;
        n2%=n;
        n0=n1;
        n1=n2;
        cnt++;
    }
    cout<<cnt<<endl;
}