#include<math.h>
#include<stdio.h>
#include<stdarg.h>
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n<=0||n>1000){
            printf("0\n");
            continue;
        }
        printf("%d\n",(int)sqrt(n));
    }
    return 0;
}