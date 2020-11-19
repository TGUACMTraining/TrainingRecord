#include<stdio.h>
int n;
int map[30][30];
void scanmap(void);
void outsidein(void);
void left(int i);
void right(int i);
void pull(int i);
void push(int i);
void printmap(void);

int main(){
    scanmap();
    outsidein();
    //printmap();

    for(int i=0;i<n;i++){
        left(i);
    //printmap();

        right(i);
    //printmap();

        if(i<n-1){
            pull(i);
    //printmap();

        }
    }for(int i=n-1;i>=0;i--){
        left(i);
    //printmap();

        right(i);
    //printmap();

        if(i>=1){
            push(i);
    //printmap();

        }
    }
    printmap();
    return 0;
}
void scanmap(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
}
void outsidein(void){
    for(int i=0;i<n;i++){
        if(!map[0][i]){
            map[0][i]=-1;
        }
        if(!map[i][0]){
            map[i][0]=-1;
        }
        if(!map[n-1][i]){
            map[n-1][i]=-1;
        }
        if(!map[i][n-1]){
            map[i][n-1]=-1;
        }
    }
}
void left(int j){
    int con=0;
    for(int i=0;i<n;i++){
        if(map[j][i]==-1){
            con=1;
        }
        if(map[j][i]==1){
            con=0;
        }
        if(con==1){
            map[j][i]=-1;
        }
    }
}
void right(int j){
    int con=0;
    for(int i=n-1;i>=0;i--){
        if(map[j][i]==-1){
            con=1;
        }
        if(map[j][i]==1){
            con=0;
        }
        if(con==1){
            map[j][i]=-1;
        }
    }
}
void pull(int i){
    for(int j=0;j<n;j++){
        if(map[i][j]==-1&&map[i+1][j]==0)
        {
            map[i+1][j]=-1;
        }
    }
}
void push(int i){
    for(int j=0;j<n;j++){
        if(map[i][j]==-1&&map[i-1][j]==0)
        {
            map[i-1][j]=-1;
        }
    }
}
void printmap(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==-1){printf("0 ");continue;}
            if(map[i][j]==0){printf("2 ");continue;}
            if(map[i][j]==1){printf("1 ");continue;}
        }
        printf("\n");
    }
}