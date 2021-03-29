#include<iostream>
#include<cstring>
using namespace std;
int w,h;
#define set0(x) memset(x,0,sizeof(x)) 
char map[25][25];//【1先看这条注释】地图
int visited[25][25];//走过的点
int cnt;//走过点的数量
int step[450][2];//这是一张计划表，计划下一步的起点 ，例如我要从 (0，3)开始走，就把step[head++]变成(0,3)
int head,tail;//head用来增加新计划,tail用来把走过的计划划掉
const int cd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void bfs(){
    while (head!=tail)//【3最后从这里看注释↓】我们还有计划没走完
    {
        for(int i=0;i<4;i++){
            int x,y;
            x=step[tail][0];y=step[tail][1];//这一步要从step[tail]这个点开始走
            x+=cd[i][0];y+=cd[i][1];//这一步有四种可能：上下左右
            if(x>0&&x<=w&&y>0&&y<=h){//每一种可能是不是真的没有出地图边界
                if(visited[x][y]==0&&map[x][y]=='.'){//每一种可能没有必要重复走以前的路，所以专挑没走过的路走，然后还不能走到墙里边去
                    visited[x][y]=1;//这一步是真可以走，所以我们走（改变后的）(x,y)
                    step[head][0]=x;//下一步可以由这个点出发
                    step[head][1]=y;
                    head++;
                    cnt++;//又走过了一个点
                }
            }
        }
        tail++;//开始走下一步计划
    }
    
}
int main(){
    while (cin>>w>>h,w&&h) 
    {
        set0(map);
        set0(visited);
        cnt=head=tail=0;
        for(int j=1;j<=h;j++){
            for(int i=1;i<=w;i++){
                cin>>map[i][j];
                if(map[i][j]=='@'){step[head][0]=i;step[head][1]=j;head++ ;visited[i][j]=1;}//【2然后是这里的注释】首先计划可以从@的点开始走
            }
        }
        cnt++;//初始点(@)已经走过了
        bfs();//这个方法就是我的世界中泼水的方法，在@泼一桶水，然后水扩展到四周
        cout<<cnt<<endl;
    }
    
}