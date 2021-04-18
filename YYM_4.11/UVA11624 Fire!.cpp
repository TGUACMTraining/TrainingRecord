#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
struct dot{
    int x,y;
}John;
const int limit=1000;
char maze[limit+10][limit+10];
bool visited[limit+10][limit+10];
int r,c;
dot q[limit*limit+100];
int steps[limit*limit+100];
int mode[limit*limit+100];
enum{j,f};
int head,tail;
int push(dot d,int mode_,int step){
    if(d.x<0||d.x==r||d.y<0||d.y==c){
        if(mode_==j){
            return step;
        }else return 0;
    }
    else{
        if(!visited[d.x][d.y]&&maze[d.x][d.y]=='.'){
            maze[d.x][d.y]=mode_==j?'J':'F';
            visited[d.x][d.y]=true;
            q[head]=d;
            mode[head]=mode_;
            steps[head]=step;
            head++;
        }
    }
    return 0;
}
int cd[5]={0,1,0,-1,0};
int key;
void p(){
    cout<<(mode[tail]==j?"JOE":"FIRE")<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<maze[i][j];
        }cout<<endl;
    }
}
int bfs(){
    while(head!=tail){
        // p();
        for(int i=0;i<4;i++){
            key=push({q[tail].x+cd[i],q[tail].y+cd[i+1]},mode[tail],steps[tail]+1);
            if(key){
                return true;
            }
        }tail++;
    }
    return 0;
}
#define clean(x) memset(x,0,sizeof(x))
int main(){
    int t;
    cin>>t;
    while(t--){
        clean(visited);
        clean(maze);
        clean(q);
        clean(steps);
        clean(mode);
        head=tail=key=0;
        cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='J'){
                    John={i,j};
                }else if(maze[i][j]=='F'){
                    visited[i][j]=true;
                    q[head]={i,j};
                    mode[head]=f;
                    head++;
                }
            }
        }
        visited[John.x][John.y]=true;
        q[head]={John.x,John.y};
        mode[head]=j;
        head++;
        if(bfs()){
            cout<<key<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
}