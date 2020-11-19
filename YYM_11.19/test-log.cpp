#include<stdio.h>
#include<math.h>
int main(){
    union{
    double i;
    char a[sizeof(double)/sizeof(char)];
    } t;
    t.i=-10;
    t.i=log(t.i);
    t.i-=t.i;
    for(int j=sizeof(double)/sizeof(char)-1;j>=0;j--)
    printf("%x",t.a[j]);
    printf("\n%lf",t.i);
    if(!(t.i>0||t.i==0||t.i<0))
    printf("\n233");
    if((double)7ffffffff8000000==(double)7ffffffff8000000)
    printf("\n233");
    return 0;
}