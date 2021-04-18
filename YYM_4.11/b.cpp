#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct dot{
    int x,y,z;
}limit,stop;
char map[40][40][40];
bool visited[40][40][40];
dot q[42875];
int step[42875];
int head,tail;
dot nd[6]={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
dot cd (dot d,int i){
    return {d.x+nd[i].x,d.y+nd[i].y,d.z+nd[i].z};
}
int s=0;
bool go(dot d){
    return d.x>=0&&d.x<limit.x&&d.y>=0&&d.y<limit.y&&d.z>=0&&d.z<limit.z&&map[d.x][d.y][d.z]!='#';
}
void bfs(){
    while(head!=tail){
        for(int i=0;i<6;i++){
            dot d=cd(q[tail],i);
            if(!go(d))continue;
            if(visited[d.x][d.y][d.z]==true)continue;
            q[head]=d;
            step[head]=step[tail]+1;
            visited[d.x][d.y][d.z]=true;
            head++;
            if(d.x==stop.x&&d.y==stop.y&&d.z==stop.z){
                s=1;
                return ;
            }
        }
        tail++;
    }
}
int main(){
    while(cin>>limit.x>>limit.y>>limit.z,limit.x){
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        head=tail=0;step[0]=0;s=0;
        for(int i=0;i<limit.x;i++){
            for(int j=0;j<limit.y;j++){
                for(int k=0;k<limit.z;k++){
                    cin>>map[i][j][k];
                    if(map[i][j][k]=='S'){
                        q[head++]={i,j,k};
                        visited[i][j][k]=true;
                    }else if(map[i][j][k]=='E'){
                        stop={i,j,k};
                    }
                }
            }
        }
        bfs();
        if(s)
        printf("Escaped in %d minute(s).\n",step[head-1]);
        else cout<<"Trapped!\n";
    }
}