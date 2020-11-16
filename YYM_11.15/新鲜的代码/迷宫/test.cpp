#include<stdio.h>
const int N=7;
int sus=0;
int map[N][N]={0};
int m,n;
/*
n行m列
nx↓my→
*/
int w;
void f(void);
typedef struct{
    int x,y;
    int from;
} dot;
dot di[]={{1,0},{0,1},{-1,0},{0,-1}};//下右上左
dot start,end;
int left,right;
dot queue[36];
//dot went[36];
void ad(dot n,int i,int l);
void Enqueue(dot n);
void printmap(void);
int main(){
    scanf("%d%d%d",&n,&m,&w);
    scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y);
    while(w--){
        int x,y;
        scanf("%d%d",&x,&y);
        map[x][y]=1;
    }
    right=left=0;
    Enqueue(start);
    queue[0].from=-1;
    while(left!=right){f();printmap();}
    for(int i=0;i<right;i++){if(queue[i].x==end.x&&queue[i].y==end.y){sus++;printf("%d ",i);}}
    printf("%d",sus);
    return 0;
}
void Enqueue(dot n)
{
    queue[right]=n;
    right++;
}
void f(void)
{
    int r=right;
    while(left<r){
        if(!(queue[left].x==end.x&&queue[left].y==end.y))
        {
            for(int i=0;i<4;i++)
            {
                int l=left;
                ad(queue[left],i,l);
                // if(queue[right-1].x==end.x&&queue[right-1].y==end.y){sus++;printf("sus++%d",right-1);}
            }
        }
        map[queue[left].x][queue[left].y]=2;
        left++;
    }
}
void ad(dot dott,int i,int l){
    dot temp;
    temp=dott;
    {printf("\n@from%d-%d",queue[temp.from].x,queue[temp.from].y);}
    {printf("now%d-%d",temp.x,temp.y);}
    temp.x+=di[i].x;
    temp.y+=di[i].y;
    {printf("temp%d-%d",temp.x,temp.y);}
    {printf("\n%d\n",temp.from);printf("right=%d\n",right);for(int i=0;i<right;i++){printf("%d-%d-%d-from%d\n",i,queue[i].x,queue[i].y,queue[i].from);}}
    if(temp.x==end.x&&temp.y==end.y){/*sus++;*//*printf("\nreturn!!sus%d i%d\n",sus,i);*/Enqueue(temp);return;}
    if(temp.x>0&&temp.y>0&&temp.x<=n&&temp.y<=m){
        {printf("in maze\n");}
        if(map[temp.x][temp.y]==0||map[temp.x][temp.y]==2){
            {printf("not on the wall\n");}
            if(temp.x!=queue[temp.from].x||temp.y!=queue[temp.from].y)
            {
                Enqueue(temp);
                {printf("didn`t went\n");}
            }
            queue[right-1].from=l;
        }
    }
}
void printmap(void)
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {printf("%d",map[i][j]);}
        printf("\n");
    }
    printf("\n\n");
}