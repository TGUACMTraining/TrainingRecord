#include<iostream>
#include<cstdio>
using namespace std;
#define dbg(x) \
{\
    cout<<"-------in line "<<__LINE__<<"-------"<<endl;\
    x;\
    cout<<"^^^^^^^line "<<__LINE__<<"ends^^^^^^"<<endl;\
}
// #define dbg(x)




const int R= 20;//计算范围
bool notprime[R]={0};//判定不是素数

int primes[100000];//用于存入素数(没有和数把素数隔开)
volatile int tail=0;//primes实际长度

int main(){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<R;i++){
        if(notprime[i]==0){
            primes[tail++]=i;
            dbg(
                cout<<"tail:"<<tail<<endl;
            )
            for(int j=2;j*i<R;j++){//划掉素数i的倍数
                notprime[i*j]=1;
            }
        }
    }
    for(int i=0;i<20;i++){
        cout<<primes[i]<<endl;
    }
}