#include<stdio.h>
struct{
    int start;
    int end;
}program[101];

int main(){
    int n;
    int i,j;
    int sum;

    while(scanf("%d",&n)!=EOF && n!=0){
        for(i=0;i<n;i++)
            scanf("%d%d",&program[i].start,&program[i].end);

        /*冒泡排序*/
        for(i=0;i<n;i++)
            for(j=0;j<n-i-1;j++)
                if(program[j].end>program[j+1].end){
                    program[100] = program[j];
                    program[j] = program[j+1];
                    program[j+1] = program[100];
                }

        /*求出最优解*/
        for(j=1,i=0,sum=1;j<n;j++)
            if(program[j].start >= program[i].end ){
                i = j;
                sum++;
            }

        printf("%d\n",sum);
    }

    return 0;
}