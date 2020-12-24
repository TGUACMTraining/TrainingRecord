#include<stdio.h>
#include<math.h>
#include<string.h>
// #define debug
#ifdef debug
#define dbg(x) do{\
    printf("on line %d:\n",__LINE__);\
    x;\
    printf("------------------------\n");\
    }while(0)
#else
#define dbg(x)
#endif
typedef struct{
    int number[500]={0};
}ln;
int digits(int);
ln fastpow(ln a,int b);
ln multiply(ln a,ln b);
void print(ln*a);
int main(){
    int p;
    scanf("%d",&p);
    ln t;
    t.number[0]=2;
    t=fastpow(t,p);
    printf("%d\n",digits(p));
    t.number[0]--;
    print(&t);
    return 0;
}
int digits(int a){
    int digit=(int)(log10(2)*a);
    return digit+1;
}
/*
5 10
5 5
5 2
5 1
*/
ln fastpow(ln a,int b){
    dbg(
        printf("caculating \n");
        print(&a);
        printf("^%d\n",b);
    );
    if(b==1){
        return a;
    }
    ln cache=fastpow(a,b/2);
    dbg(
        printf("cache=\n");
        print(&cache);
    );
    if(b%2){
        return multiply(multiply(cache,cache),a);
    }else{
        return multiply(cache,cache);    
    }
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
                c.number[499]%=10;
            }
        }
    }
    dbg(
        print(&c);
    );
    return c;
}