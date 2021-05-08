#include<iostream>  
#include<cstdio>
using namespace std;
int a[6000];
long long tail;
int b;
int main(){
    while(isdigit(a[tail]=getchar()))a[tail++]-='0';
    cin>>b;
    long long cache=0,flag=0;
    for(int i=0;i<tail;i++){
        cache=10*cache+a[i];
        if(cache/b)flag=1;
        if(flag){
            cout<<cache/b;
            cache%=b;
        }
    }
    if(flag==0)cout<<0;
}