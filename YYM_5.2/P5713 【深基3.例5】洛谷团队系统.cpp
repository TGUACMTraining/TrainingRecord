#include<iostream>
using namespace std;
int main(){
    int online;
    int local;
    int n;
    cin>>n;
    online=11+3*n;
    local=5*n;
    if(local<online){
        cout<<"Local";
    }else{
        cout<<"Luogu";
    }
}