#include<iostream>
using namespace std;
const int limit =100+10;
char mp[limit][limit];
int n,m;
int head,tail;
struct dot{
    int x,y;
}q[limit*limit];
int cd[][2]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
    {1,1},
    {-1,1},
    {1,-1},
    {-1,-1},
};
void bfs(char c){
    while(head!=tail){
        for(int i=0;i<8;i++){
            int x=q[tail].x;
            int y=q[tail].y;
            x+=cd[i][0];
            y+=cd[i][1];
            if(x>=0&&y>=0&&x<n&&y<m){
                if(mp[x][y]=='W'){
                    mp[x][y]=c;
                    q[head++]={x,y};
                }
            }
        }tail++;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    char c='!';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='W')
            {
                head=tail=0;
                q[head++]={i,j};
                bfs(c);
                c++;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<mp[i][j];
    //     }cout<<endl;
    // }
    cout<<c-'!'<<endl;
}