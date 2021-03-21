#include<iostream>
#include<algorithm>
using namespace std;
const unsigned int limit=50000;
struct{
    bool notprime[limit+10]={0};
    unsigned int primes[limit/13+5000]={0};
    unsigned int tail=0;
    void build(){
        notprime[0]=notprime[1]=1;
        for(unsigned int i=2;i<limit;i++){
            if(notprime[i]==0)primes[tail++]=i;
            for(int j=0;j<tail;j++){
                if(i*primes[j]>limit)break;
                notprime[i*primes[j]]=1;
                if(i%primes[j]==0)break;
            }
        }
    }
}prime_base;
const unsigned int lim=(int)1.2e6;
struct {
    unsigned int l,r;
    bool notprime[lim]={0};
    unsigned int primes[lim/13+5000]={0};
    unsigned int tail=0;
    void build(){
        if(l<2)l=2;
        for(int i=0;i<prime_base.tail;i++){
            int j;
            j=l/prime_base.primes[i];
            if(j*prime_base.primes[i]!=l)j++;
            if(j==0||j==1)j=2;
            for(;j*prime_base.primes[i]<=r;j++){
                notprime[j*prime_base.primes[i]-l]=1;
            }
        }
        for(int i=l;i<=r;i++){
            if(!notprime[i-l])
            {primes[tail++]=i;}
        }
    }

}primes;

int main(){
    prime_base.build();
    cin>>primes.l>>primes.r;
    primes.build();
    cout<<primes.tail<<endl;
}