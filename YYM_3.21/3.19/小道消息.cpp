#include<iostream>
using namespace std;
const int limit=(int)1.5e7;
bool notprime[limit];
int primes[limit/13+5000];
int tail;
void build(){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<limit;i++){
        if(notprime[i]==0)primes[tail++]=i;
        for(int j=0;j<tail;j++){
            if(primes[j]*i>=limit)break;
            notprime[primes[j]*i]=1;
            if(i%primes[j]==0)break;
        }
    }
}
bool checkprime(long long p){
    if(p<limit)return !notprime[p];
    for(int i=0;i<tail;i++){
        if(p%primes[i]==0)return false;
    }
    return true;
}
int main(){
    build();
    long long n;
    long long k;
    int flag=1;
    cin>>n>>k;
    n++;
    k++;
    if(checkprime(k)&&n<2*k)cout<<1<<endl;
    else cout<<2<<endl;

}
/*
素数有倍数
1倍数外其他数（质数）（a-2a）
2质数到倍数
素数无倍数
1其他全部数
和数a
1a互质的质数b及b的和数
2
*/