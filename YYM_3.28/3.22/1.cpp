#include<iostream>
using namespace std;
const int limit=1e6;
bool notprime[limit+10];
int prime[limit/13+5000];
int tail;
void build(){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<limit;i++){
        if(notprime[i]==0)prime[tail++]=i;
        for(int j=0;j<tail;j++){
            if(i*prime[j]>limit)break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
inline int fun(int n){
    return  n*n+n+41;
}
int main(){
    build();
    int x,y;
    while(cin>>x>>y,x||y){
    int flag=1;
    for(int i=x;i<=y;i++){
        if(notprime[fun(i)]){
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<"OK"<<endl;
    }else{
        cout<<"Sorry"<<endl;
    }
    }
}