#include<iostream>
#include<cstdio>
using namespace std;
// #define dbg(x) \
{\
    cout<<"-------in line "<<__LINE__<<"-------"<<endl;\
    x;\
    cout<<"^^^^^^^line "<<__LINE__<<" ends^^^^^^"<<endl;\
}
#define dbg(x)

const int R= 1000000;
bool notprime[R]={0};
volatile int tail;
int primes[100000];
void print(int n,int a,int b){
    printf("%d = %d + %d\n",n,a,b);
}
int main(){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<R;i++){
        
        if(notprime[i]==0){
            dbg(cout<<tail<<endl;)
            primes[tail++]=i;
            for(int j=2;j*i<R;j++){
                notprime[i*j]=1;
            }
        }
    }
    dbg(for(int i=0;i<10;i++){
        cout<<primes[i]<<endl;
    })
    int n;
    while(scanf("%d",&n),n){
        for(int index=0;index<tail;index++){
            if(notprime[n-primes[index]]==0){
                print(n,primes[index],n-primes[index]);
                break;
            }
        }
    }
}