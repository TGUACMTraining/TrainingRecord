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

const int R= 10000000;
bool notprime[R]={0};
volatile int tail;
int primes[700000];
void print(int n,int a,int b){
    printf("%d = %d + %d\n",n,a,b);
}
void it(void){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<R;i++){
        
        if(notprime[i]==0){
            primes[tail++]=i;
            for(int j=2;j*i<R;j++){
                notprime[i*j]=1;
            }
        }
    }
}
int breakup(int n){
    for(int index=0;index<tail;index++){
            if(notprime[n-primes[index]]==0){
                return primes[index];
                // print(n,primes[index],n-primes[index]);
                break;
            }
    }
}
int main(){
   it();
   dbg(
       for(int i=0;i<10;i++){
           cout<<i<<" "<<notprime[i]<< endl;
       }
   )
   dbg(cout<<tail<<endl;)
   int n;
   while(cin>>n){
       if(n<8){cout<<"Impossible."<<endl;continue;}
       int cache;
       switch (n%2)
       {
       case 1:
           cout<<"2 3 "<<(cache=breakup(n-=5))<<" "<<n-cache<<endl;
           break;
       
       default:
       cout<<"2 2 "<<(cache=breakup(n-=4))<<" "<<n-cache<<endl;
           break;
       }
   }
}