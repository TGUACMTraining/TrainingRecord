#include<iostream>
using namespace std;
int a,b;
int q[6000000][2];
int visited[101000];
int head,tail;
int next(int mode,int i){
    switch(mode){
        case 0:
        return i+1;
        case 1:
        return i-1;
        case 2:
        return i*2;
    }
}
void bfs(){
    while (head!=tail)
    {
        for(int i=0;i<3;i++)
        {
            int n=next(i,q[tail][0]);
            if(n<0||n>1e5+10)continue;
            if(visited[n]==1)continue;
            visited[n]=1;
            if(n==b){
                cout<<q[tail][1]+1<<endl;
                goto flag;
            }
            q[head][0]=n;
            q[head][1]=q[tail][1]+1;
            head++;
        }
        tail++;
    }
    flag:;
}
int main(){
    cin>>a>>b;
    if(b<=a){cout<<a-b<<endl;return 0;}
    q[head++][0]=a;
    bfs();

}