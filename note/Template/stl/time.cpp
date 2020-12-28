#include<stdio.h>
#include<time.h>
int main(){
    double a;
    int p;
    a=clock();
    for(p=0;p<100000;p++){
        int k=0;
        for(k=0;k<10000;k++){
            int n=p+k;
        }
    }
    a-=clock();
    a=-a;
    printf("%lf",a);
    return 0;
}