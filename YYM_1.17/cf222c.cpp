#include<bits/stdc++.h>
using namespace std;
// #define isprime_end 10
#define isprime_end (int)(1e7+0.5)
// #define zip 10
#define zip 664580
#define print_time \
    cout<<"in line "<<__LINE__<<endl;\
    cout<<clock()-times<<endl;\
    times=clock();
int main(){

    int times=clock();
    static unsigned int prime[zip]={0};
    unsigned int prime_end=0;
    static int breakup[zip]={0};

    static bool isprime[isprime_end]={0};
    isprime[0]=1;
    isprime[1]=1;
    for(int index=2;index<isprime_end;index++){
        if(!isprime[index]){
            for(int times=2;times*index<isprime_end;times++){


                isprime[times*index]=1;
            }
            prime[prime_end++]=index;
        }
    }

    print_time
    int n,m;
    cin>>n>>m;
    int cache;
    int index;
    while(n--){
        scanf("%d",&cache);
        for(int index=0;cache>1;index++){
            while(cache%prime[index]==0){
                cache/=prime[index];
                breakup[index]++;
            }
        }
    }
    while(m--){
        scanf("%d",&cache);
        for(int index=0;cache>1;index++){
            while(cache%prime[index]==0){
                cache/=prime[index];
                breakup[index]--;
            }
            index++;
        }
    }
    print_time

    int num,den;
    num=den=0;
    stack<int> fz;
    stack<int> fm;
 
    for(int i=0;i<zip;i++){
        if(breakup[i]>0){while(breakup[i]--){fz.push(prime[i]);}}
        else if(breakup[i]<0){while(breakup[i]++){fm.push(prime[i]);}}
    }   
    print_time
 
    if(fz.empty()){fz.push(1);}
    if(fm.empty()){fm.push(1);}
    // cout<<fz.size()<<" "<<fm.size()<<endl;
    printf("%d %d\n",fz.size(),fm.size());
    while(!fz.empty()){
        printf("%d ",fz.top());
        fz.pop();
    }
    cout<<endl;
    while(!fm.empty()){
        printf("%d ",fm.top());
        fm.pop();
    }
    return 0;
}