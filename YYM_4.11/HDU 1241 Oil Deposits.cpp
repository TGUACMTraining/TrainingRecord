#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char plot[110][110];
bool visited[110][110];
struct dot{
    int x,y;
};
dot q[10000+100];
int tail,head;
dot cd[8]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
    {1,1},
    {1,-1},
    {-1,1},
    {-1,-1},
};
int m,n;
// void print(){
//     cout<<endl;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<plot[i][j];
//         }cout<<endl;
//     }cout<<endl;
// }
// void pq(){
//         cout<<"----------------------------\n";
//     for(int i=0;i<head;i++){
//         cout<<"("<<q[i].x<<","<<q[i].y<<")"<<endl;
//     }
// }
void bfs(char c){
    while(tail!=head){
        for(int i=0;i<8;i++){
            int x=q[tail].x+cd[i].x;
            int y=q[tail].y+cd[i].y;
            if(x>=0&&x<m&&y>=0&&y<n)
            {
                if(!visited[x][y]&&plot[x][y]=='@'){
                    plot[x][y]=c;
                    visited[x][y]=true;
                    q[head++]={x,y};
                }
            }
        }
        // pq();
        tail++;
    }
}
#define clean(x) memset(x,0,sizeof(x))
int main(){
    while(cin>>m>>n,m||n){
        clean(visited);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>plot[i][j];

            }
        }
        char c='A';
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(plot[i][j]=='@'){
                    head=tail=0;
                    q[head++]={i,j};
                    visited[i][j]=true;
                    plot[i][j]=c;
                    bfs(c++);
                    // print();
                }
            }
        }
        cout<<(int)(c-'A')<<endl;
    }
}