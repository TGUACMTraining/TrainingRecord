#include<iostream>
using namespace std;
int main(){
    long long a1,a2,d,n;
    cin>>a1>>a2>>n;
    d=a2-a1;
    cout<<(2*a1+(n-1)*d)*n/2<<endl;
}