#include<iostream>
using namespace std;
int main(){
    int x1,x2,v1,v2,a;
    cin>>x1>>v1;
    cin>>x2>>v2>>a;
    int cnt=0;
    while(2*x1+2*v1*cnt>2*x2+2*v2*cnt+a*cnt*cnt){
        cnt++;
    }
    cout<<cnt<<endl;
}