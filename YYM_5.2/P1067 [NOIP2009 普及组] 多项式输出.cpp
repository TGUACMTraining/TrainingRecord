#include<iostream>
using namespace std;
int head=0;
void output(int n,int a){
    if(a==0)return ;
    if(a>0){if(head)cout<<"+";}
    head=1;
    if(a<0){
        cout<<"-";
        a=-a;
    }
    if(a!=1)cout<<a;
    if(n==1){cout<<"x";return;}
    else if(n==0){return ;}
    else {cout<<"x^"<<n;}
}
int main(){
    int n;
    cin>>n;
    for(int i=n;i>0;i--){
        int a;
        cin>>a;
        output(i,a);
    }
    int a;
    cin>>a;
    if(a>0)cout<<"+"<<a;
    else if(a<0)cout<<a;
}