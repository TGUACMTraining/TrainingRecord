#include<iostream>
using namespace std;
const int limit=50000000;
bool notprime[limit];
int primes[limit/13+5000];
int tail=0;
void build(){
    notprime[0]=notprime[1]=true;
    for(int i=0;i<limit;i++){
        if(!notprime[i]){
            primes[tail++]=i;
        }
        for(int j=0;j<tail;j++){
            if(i*primes[j]>=limit)break;
            notprime[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
}
int arr[30];
int visited[30];
int n,k;
int cnt=0;
void dfs(int k,int num,int s){
    if(k==1){
        for(int i=s;i<n;i++){
            if(visited[i]==0){
                if(notprime[num+arr[i]]==0)cnt++;
            }
        }    
    }    
    for(int i=s;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            dfs(k-1,num+arr[i],i+1);
            visited[i]=0;
        }
    }
}
int main(){
    build();
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dfs(k,0,0);
    cout<<cnt<<endl;
}