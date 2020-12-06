#include<stdio.h>
// #define debug
#ifdef debug
#define dbg(x) {x;}
#else 
#define dbg(x) 
#endif
int flag_color[52][3]={0};
enum{W,B,R};
int n,m;
int color(int begin,int end,char c);
int main(){
    scanf("%d%d",&m,&n);
    char cache;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&cache);
            switch(cache){
                case 'W':flag_color[i][B]++;flag_color[i][R]++;break;
                case 'B':flag_color[i][W]++;flag_color[i][R]++;break;
                case 'R':flag_color[i][W]++;flag_color[i][B]++;break;
            }
        }
    }
    dbg(
        for(int t=0;t<m;t++){
            printf("line:%d\t",t);
            printf("!w=%d\t",flag_color[t][W]);
            printf("!B=%d\t",flag_color[t][B]);
            printf("!R=%d\t",flag_color[t][R]);
            printf("\n");
        }
    )
    int changed=10000;
    int thistime[3];
    for(int x=0;x<m-2;x++){
        dbg(
            printf("try 0-%d W\n",x);
        )
        thistime[W]=color(0,x,'W');
        for(int y=x+1;y<m-1;y++){
            dbg(
                printf("try %d-%d B\n",x+1,y);
            )
            thistime[B]=color(x+1,y,'B')+thistime[W];
            dbg(
                printf("try %d-%d R\n",y+1,m-1);
            )
            thistime[R]=color(y+1,m-1,'R')+thistime[B];
            dbg(printf("thistime=%d\n",thistime))
            changed=thistime[R]<changed?thistime[R]:changed;
            dbg(printf("changed=%d\n\n\n",changed);)
        }
    }
    printf("%d",changed);
    return 0;
}
int color(int begin,int end,char c){
    int i;
    int cache=0;
    dbg(
        printf("c=%c\t",c);
    )
    switch(c){
        case 'W':c=W;dbg(printf("catch W\t"););break;
        case 'B':c=B;dbg(printf("catch B\t"););break;
        case 'R':c=R;dbg(printf("catch R\t"););break;
    }
    dbg(
        printf("get %d\n",c);
    )
    for(i=begin;i<=end;i++){
        cache+=flag_color[i][c];
        dbg(printf("line%d:cache=%d\n",i,cache);)
    }
    return cache;
}