#include<stack>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int map[30][30];
int lim_x,lim_y;
int x0,y0;
int change[4][2]={{0,1},{1,0},{0,-1},{-1,0},};
stack<pair<int ,int > > st;
void dfs(int x_,int y_){
    for(int i=0;i<4;i++){
        int x=x_+change[i][0],y=y_+change[i][1];
        if(x>0&&x<=lim_x&&y>0&&y<=lim_y&&)
    }
}
int main(){
    while(cin>>lim_y>>lim_x){
        for(int i=0;i<lim_x;i++){
            for(int j=0;j<lim_y;j++)
            {
                cin>>map[i][j];
                x0=i;
                y0=j;
            }            
        }
    }
}