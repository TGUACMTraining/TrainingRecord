#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int limit=(int)1E8;
bool notprime[limit+10];
int prime[(int)limit/13+5000];
int tail=0;
void build(){
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
int main(){
    build();
    int n;
    while (~scanf("%d",&n))
    {
        printf("%d\n",((int*)upper_bound(prime,prime+tail,n)-(int*)prime));
    }
    
}