#include<stdio.h>
#include<string.h>
#define dbg(x) do{\
    printf("on line %d:\n",__LINE__);\
    x;\
    printf("------------------------\n");\
    }while(0)
typedef struct{
    int number[500]={0};
}ln;
ln multiply(ln a,ln b);
void print(ln*a);
int main(){
    ln a,b;
    a.number[0]=2;
    b.number[0]=8;
    a=multiply(a,b);
    print(&a);
    return 0;
}
void print(ln*a){
    int i=500;
    do{
        printf("%d",(*a).number[--i]);
        if(!(i%50)){
            printf("\n");
        }
    }while(i);
}
ln multiply(ln a,ln b){
    int i=0,j=0,k=0;
    ln c;
    dbg(
        print(&a);
        printf("\n");
        print(&b);
    );
    for(i=0;i<500;i++){
        for(j=0;j<500;j++){
            if(i+j<500){
                k=i+j;
                c.number[k]+=a.number[i]*b.number[j];
                dbg(
                    print(&c);
                );
                while(k+1<500&&c.number[k]/10){
                    dbg(
                        printf("%d\n",c.number[k]/10);
                        printf("k=%d\n",k);
                        printf("k+1=%d\n",k+1);
                        printf("%d\n",c.number[k+1]);
                    );
                    c.number[k+1]+=(c.number[k]/10);
                    dbg(
                        printf("%d\n",c.number[k+1]);
                        print(&c);
                    );
                    c.number[k]%=10;
                    dbg(
                        print(&c);
                    );
                    k++;
                }
            }else {
                break;
            }
        }
    }
    dbg(
        print(&c);
    );
    return c;
}