#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char maze [35][35][35];
int q[40000][4];
int head;
int tail;
int x,y,z;
int stop[3];
int change[6][3]={
    {1,0,0},{0,1,0},{0,0,1},
    {-1,0,0},{0,-1,0},{0,0,-1},
};
int steps=0;
void clear(){
    memset(maze ,0,sizeof(maze));
    head=tail=0;
    steps=0;
}
void bfs(){
    while(tail!=head){
        for(int i=0;i<6;i++){
            int nx=q[tail][0]+change[i][0];
            int ny=q[tail][1]+change[i][1];
            int nz=q[tail][2]+change[i][2];
            if(nx>0&&nx<=x&&ny>0&&ny<=y&&nz>0&&nz<=z){
                if(maze[nx][ny][nz]=='.'){
                    q[head][0]=nx;
                    q[head][1]=ny;
                    q[head][2]=nz;
                    q[head][3]=q[tail][3]+1;
                    maze[nx][ny][nz]='#';
                    head++;
                }
                else if(nx==stop[0]&&ny==stop[1]&&nz==stop[2]){
                    steps=q[tail][3]+1;
                    goto flag;
                }
            }
        }      
        tail++;
    }
    flag:
    1;
}
int main(){
    while(cin>>x>>y>>z,x&&y&&z){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                for(int k=1;k<=z;k++){
                    cin>>maze[i][j][k];
                    if(maze[i][j][k]=='S'){
                        q[0][0]=i;
                        q[0][1]=j;
                        q[0][2]=k;
                        q[0][3]=0;
                        maze[i][j][k]='#';
                        head++;
                    }else if(maze[i][j][k]=='E'){
                        stop[0]=i;
                        stop[1]=j;
                        stop[2]=k;
                    }
                }
            }
        }
        bfs();
        if(steps){
            printf("Escaped in %d minute(s).",steps);
        }else printf("Trapped!");
        cout<<endl;
        clear();
    }
}