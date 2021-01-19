#include<iostream>
using namespace std;
int f(int a){
    if(a%10)return a%10;
    if(a==0)return 0;
    else return f(a/10);
}
int s(int p,int q){
    int cache=0;
    for(;p<=q;p++){
        cache+=f(p);
    }
    return cache;
}
int main(){
    int a,b;
    while (1)
    {
        cin>>a>>b;
        if(a<0&&b<0){
            break;
        }
        else cout<<s(a,b)<<endl;
    }
    return 0;    
}