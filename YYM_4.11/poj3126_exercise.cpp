#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int limit=10000;
bool notprime[limit];
int prime[limit];
int head;
int tail;
int from,to;
void build(){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<limit;i++){
        if(!notprime[i]){
            prime[tail++]=i;
        }
        for(int j=0;j<tail;j++){
            if(prime[j]*i>=limit)break;
            notprime[prime[j]*i]=true;
            if(i%prime[j]==0)break;
        }
    }
}
int q[limit];
int step[limit];
bool visited[limit];
int change(int num,int index,int n){
    int power=1;
    int result=0;
    for(int i=0;i<4;i++){
        if(i==index){
            result+=n*power;
        }else{
            result+=num%10*power;
        }
        power*=10;
        num/=10;
    }
    return result;
}
int bfs(){
    while(head!=tail){
        if(q[tail]==to)return step[tail];
        for(int i=0;i<4;i++){
            for(int j=0;j<10;j++){
                int cache=change(q[tail],i,j);
                if(cache>999&&!notprime[cache]&&!visited[cache]){
                    visited[cache]=true;
                    q[head]=cache;
                    step[head]=step[tail]+1;
                    head++;
                }
            }
        }
        tail++;
    }
    return -1;
}
#define clean(x) memset(x,0,sizeof(x));
int main(){
    build();
    int cases;
    cin>>cases;
    while(cases--){
        cin>>from>>to;
        head=tail=0;
        clean(visited);
        clean(step);
        clean(q);
        q[head++]=from;
        int r=bfs();
        if(r==-1){
            cout<<"Impossible"<<endl;
        }else{
            cout<<r<<endl;
        }
    }
}