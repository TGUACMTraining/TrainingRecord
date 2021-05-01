#include<iostream>
using namespace std;
int main(){
    int m,t,s;
    cin>>m>>t>>s;
    int cache;
    if(t)
    cout<<(((cache=(m-s/t-(int)(s%t?1:0)))>0)?cache:0)<<endl;
    else 
    cout<<0<<endl;
}