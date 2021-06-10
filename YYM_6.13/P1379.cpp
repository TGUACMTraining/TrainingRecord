#include<unordered_set>
#include<iostream>  
using namespace std;
unordered_set<int>visited;
int e=123804765;
int queue[(int)4e5];
int stp[(int)4e5];
int head;
int tail;
void push(int num,int step){
    stp[head]=step;
    queue[head++]=num;
}
int pop(int &step){
    step=stp[tail];
    return queue[tail++];
}
#define rg register
int cd[]={0,1,0,-1,0};
void inline rebuild(rg int &x,int (&mp)[3][3]){
    x=0;
    for(rg int i=0;i<3;i++){
        for(rg int j=0;j<3;j++){
            x*=10;x+=mp[i][j];
        }
    }
}
int bfs(){
    while(head!=tail){
        int step;
        int now=pop(step);
        if(now==e)return step;
        int x=0;
        int y=0;
        int mp[3][3];
        for(int i=2;i>=0;i--){
            for(int j=2;j>=0;j--){
                mp[i][j]=now%10;
                if(!mp[i][j]){
                    x=i;y=j;
                }
                now/=10;
            }
        }
        for(int i=0;i<4;i++){
            int xx=x+cd[i];
            int yy=y+cd[i+1];
            if(xx>=0&&xx<3&&yy>=0&&yy<3){
                swap(mp[xx][yy],mp[x][y]);
                int nw;
                rebuild(nw,mp);
                if(!visited.count(nw)){
                    visited.insert(nw);
                    push(nw,step+1);
                    if(nw==e)return step+1;
                }
                swap(mp[xx][yy],mp[x][y]);
            }
        }
    }
}
int main(){
    int b;
    cin>>b;
    push(b,0);
    cout<<bfs();
}