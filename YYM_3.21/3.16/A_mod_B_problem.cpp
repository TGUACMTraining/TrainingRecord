#include<iostream>
#include<cstdio>
using namespace std;
const int limit=1000100;
bool notprime[limit+10];
int prime[100000];
int tail=0;
void build(void){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<=limit;i++){
        if(!notprime[i])prime[tail++]=i;
        for(int j=0;j<tail;j++){
            if(prime[j]*i>limit)break;
            notprime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int num[limit+10]={0};
int main(){
    build();
    int n;
    int m;
    cin>>n>>m;
    for(int i=1;i<=m+30;i++){
        num[i]=num[i-1];
        if(!notprime[i])num[i]++;
    }
    int l,r;
    while(n--){
        scanf("%d%d",&l,&r);
        if(min(1,min(l,r))==1&&max(m,max(l,r))==m)
        cout<<num[r]-num[l-1]<<endl;
        else{cout<<"Crossing the line"<<endl;}
    }
}
// 1 2 3 4 5 6 7 8 9
// 0 1 2 2 3 3 4 4 4
