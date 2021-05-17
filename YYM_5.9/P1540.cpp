#include<iostream>
#include<set>
using namespace std;
int n,m;
int q[1010];
int head;
int tail;
set<int>mem;
void ask(int num){
    if(mem.count(num))return ;
    mem.insert(num);
    q[head++]=num;
    if(head-tail==m+1){
        mem.erase(q[tail++]);
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int cache;
        cin>>cache;
        ask(cache);
    }
    cout<<head<<endl;
}