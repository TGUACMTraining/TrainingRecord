#include<stdio.h>
int main(){
    int n,m;
    int cache_x1,cache_y1;
    int cache_x2,cache_y2;
    scanf("%d%d",&n,&m);
    int map[n+2][n+2]={0};
    while(m--){
        scanf("%d%d",&cache_x1,&cache_y1);
        scanf("%d%d",&cache_x2,&cache_y2);
        while(cache_x1<=cache_x2){
            ++map[cache_x1][cache_y1];
            --map[cache_x1][cache_y2+1];
            ++cache_x1;
        }
    }
    for(int i=1;i<=n;i++){
        int cache=0;
        for(int j=1;j<=n;j++){
            cache+=map[i][j];
            printf("%d ",cache);
        }
        printf("\n");
    }
    return 0;
}