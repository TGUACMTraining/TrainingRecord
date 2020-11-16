#include<stdio.h>
#define N 10
typedef struct{
    int x;
    int y;
    int from;
} dot;
int sus=0;
dot di[4]={
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};
int mappoint(dot);
int been(dot);
dot begin,end;
dot queue[100000];
int map[N][N]={0};
int left=0,right=0;
void Enqueue(dot apoint);
int x,y,t;
void bfs(void);
int inmap(dot);
int main(){
    scanf("%d%d",&x,&y);
    //printf("迷宫大小\n");
    scanf("%d",&t);
    // printf("障碍数量\n");
    scanf("%d%d%d%d",&begin.x,&begin.y,&end.x,&end.y);
    // printf("起点终点\n");
    Enqueue(begin);
    // printf("begin入队");
    queue[0].from=-1;
    for(;t--;){
        dot d;
        scanf("%d%d",&d.x,&d.y);
        // printf("设置点");
        map[d.x][d.y]=1;
    }
    while(left<right)bfs();
    printf("%d",sus);
    return 0;
}
void Enqueue(dot apoint){
    queue[right++]=apoint;
    // printf("%d-%d,%d",apoint.x,apoint.y,apoint.from);
}
int equal(dot point1,dot point2){
    if(point1.x==point2.x&&point1.y==point2.y){return 1;}
    else{return 0;}
}
dot shift(dot point,int i){
    point.x+=di[i].x;
    point.y+=di[i].y;
    return point;
}
int jud(dot dian){
    int t=0;
    if(mappoint(dian)==0)
    {
        if(!equal(dian,end))
        {
            if(inmap(dian)){
                if(!been(dian))t=1;//
            }
        }
        else sus++;
    }
    return t;
}
int mappoint(dot dian){
    return map[dian.x][dian.y];
}
void bfs(void){
    int r=right;
    while(left<r){
    // printf("while bfs\n");
        for(int i=0;i<4;i++){
            // printf("for bfs\n");
            dot point=shift(queue[left],i);
            if(jud(point)){Enqueue(point);queue[right-1].from=left;}//
        }left++;
    }
}
int been(dot dian){
    int t=0;
    int p;
    p=dian.from;
    while(p!=-1){
        //printf("been while\n");
        if(equal(queue[p],dian)){t=1;break;}
        p=queue[p].from;
    }return t;
}
int inmap(dot dian){
    int i=0;
    if(dian.x>0&&dian.y>0&&dian.x<=x&&dian.y<=y)
    i=1;
    return i;
}