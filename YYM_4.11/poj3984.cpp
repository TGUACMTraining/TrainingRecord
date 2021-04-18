#include<iostream>
using namespace std;
struct dot
{
    int x,y;
};
int arr[5][5];
bool visited[5][5];
dot q[100];
int from[100];
int head,tail;
int cd[]={0,1,0,-1,0};
int bfs(){
    while(head!=tail){
        for(int i=0;i<4;i++){
            int x=q[tail].x+cd[i];
            int y=q[tail].y+cd[i+1];
            if(x==4&&y==4){
                return tail;
            }
            if(x>=0&&x<5&&y>=0&&y<5)
            if(arr[x][y]==0&&!visited[x][y]){
                visited[x][y]=true;
                from[head]=tail;
                q[head++]={x,y};
            }
        }tail++;
    }
}
int st[100];
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    head++;
    int t=bfs();
    for(int i=tail;i!=0;i=from[i]){
        st[++st[0]]=i;
    }
    cout<<"(0, 0)"<<endl;
    for(int i=st[0];i!=0;i--){
        cout<<"("<<q[st[i]].x<<", "<<q[st[i]].y<<")"<<endl;
    }
    cout<<"(4, 4)"<<endl;
}