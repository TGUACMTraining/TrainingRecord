#include<iostream>
using namespace std;
const int limit=1e4;
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
void test(int n){
    int cnt=0;
    for(int i=0;prime[i]<n/2;i++){
        if(notprime[n-prime[i]]==0)cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    build();
    int n;
    while(cin>>n,n){
        test(n);
    }
}