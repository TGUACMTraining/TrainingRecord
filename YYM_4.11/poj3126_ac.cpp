#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int limit=10000;
bool notprime[limit];
int prime[limit/13+5000];
int tail;
bool visited[10000];
void build(){
    notprime[0]=notprime[1]=true;
    for(int i=2;i<limit;i++){
        if(!notprime[i]){
            prime[tail++]=i;
        }
        for(int j=0;j<tail;j++){
            if(i*prime[j]>=limit){
                break;
            }
            notprime[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    
}
int q[limit];
int steps[limit];
int head;
int s,e;
int change(int num,int index,int to){
    int result=0;
    int power=1;
    for(int i=0;i<4;i++){
        if(i!=index)
        result+=num%10*power;
        else{
            result+=to*power;
        }
        power*=10;
        num/=10;
    }
    return result;
}
int bfs(){
    while(head!=tail){
        int cache=q[tail];
        if(cache==e)return steps[tail];

        for(int d=0;d<4;d++){
            for(int to=0;to<10;to++){
                int changed=change(cache,d,to);
                if(!notprime[changed]&&changed!=cache&&changed>999&&!visited[changed]){

                    q[head]=changed;
                    steps[head]=steps[tail]+1;
                    head++;
                    visited[changed]=true;

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
    int n;
    cin>>n;
    while(n--){
        clean(visited);
        clean(steps);
        head=tail=0;
        tail=0;
        cin>>s>>e;
        q[head++]=s;
        visited[s]=true;
        int step=bfs();
        if(step==-1){
            cout<<"Impossible"<<endl;
        }else 
        {
            // for(int i=0;i<head;i++){
            //     cout<<q[i]<<" ";
            // }cout<<endl;
            cout<<step<<endl;
        }
    }
}