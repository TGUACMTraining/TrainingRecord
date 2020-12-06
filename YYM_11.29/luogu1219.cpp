#include<stdio.h>
// #define debug
#ifdef debug
#define dbg(x) {x;}
#define def(x) x
#else
#define dbg(x) 
#define def(x)
#endif
struct{
    int x;
    int y;
}node[6];
int _y[13];
int _xpy[27];
int no_one_will_use_this_name[27];
int *_xmy;
int map[13]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
def(int map_2[13][13];)
void search(int k,int depth);
def(void printmap(void);)
int n;
int sus=0;
int three=3;
int main(){
    _xmy=&no_one_will_use_this_name[13];
    scanf("%d",&n);
    search(0,0);
    printf("%d",sus);
    return 0;
}
void search(int k,int depth){
    dbg(
        printf("try @n=%d k=%d depth=%d\n",n,k,depth);
    )
    dbg(printf("\n\t\tchanged depth=%d",depth);)
    for(int width=0;width<n;width++){
        dbg(printf("\n\t\twidth=%d",width))

        if(!(_y[width]||_xpy[depth+width]||_xmy[depth-width])){
            dbg(printf("\t\t\t\t\t\t\t\t_y[depth=%d]=%d _xpy[depth+width=%d]=%d _xmy[depth-width=%d]=%d\n",width,_y[width],depth+width,_xpy[depth+width],depth-width,_xmy[depth-width]))

            dbg(printf("\n\t\t\t\tthis way:\t\t\t\t\tx:%d y:%d\n",depth,width));
            dbg(map_2[depth][width]=1;)
            _y[width]++;
            _xpy[depth+width]++;
            _xmy[depth-width]++;
            map[depth]=width;
            dbg(printmap();)
            dbg(printf("\t\t\t\t\t\t\t\t_y[depth=%d]=%d _xpy[depth+width=%d]=%d _xmy[depth-width=%d]=%d\n",width,_y[width],depth+width,_xpy[depth+width],depth-width,_xmy[depth-width]))
            if(k==n-1){
                if((three)&&(map[0]+1)&&(map[1]+1)&&(map[2]+1)&&(map[3]+1)&&(map[4]+1)&&(map[5]+1))
                {
                    for(int i=0;i<n;i++){
                        printf("%d ",map[i]+1);
                    }
                    printf("\n");
                    three--;
                }sus++;
                
            }else search(k+1,depth+1);
            _y[width]--;
            _xpy[depth+width]--;
            _xmy[depth-width]--;
            map[depth]=-1;
            dbg(map_2[depth][width]=0;)
            dbg(printf("\nwasted---------------------------------\n"))
        }
    }

}
def(
    void printmap(void)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",map_2[i][j]);
            }
            printf("\n");
        }
    }
)
