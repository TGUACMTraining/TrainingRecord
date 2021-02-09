#include<iostream>
using namespace std;
int vt,v0;
int length(int a){
    return a*vt-a*a*v0;
}
int judge(int a,int b){
    int la,lb;
    la=length(a);
    lb=length(b);
    if(la==lb)return 0;
    if(la>lb)return a;
    if(la<lb)return b;
}
int main(){
    while(cin>>vt>>v0,vt||v0){
        double n=vt/2.0/v0;
        cout<<judge((int)n,(int)(n+1))<<endl;
    }
}