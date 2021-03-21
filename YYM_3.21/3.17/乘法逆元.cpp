/*
p=ki+r
k[r]+[i]==0(%p)
[i]==-k[r](%p)
[i]==-k[(p%i)]
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long *inv;
int main(){
    int n;int p;
    inv= new long long [3000010];
    memset(inv,3000010*sizeof(long long),0);
    inv[0]=0;
    inv[1]=1;
    scanf("%d%d",&n,&p);
    printf("1\n");
    for(int i=2;i<=n;i++){
         inv[i]=(long long)p-(p/i)*inv[p%i]%p;
        printf("%lld\n",inv[i]);
    }
    
}