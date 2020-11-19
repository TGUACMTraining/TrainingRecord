#include<stdio.h>
//#define debug
#ifdef debug
#define debpri printf
#else 
#define debpri //
#endif
int t;
long arr[1000000];
int find(long q);
int main(){
    int questions;
    scanf("%d",&t);
    scanf("%d",&questions);
    for(int i=0;i<t;i++){
        scanf("%ld",&arr[i]);
        //debpri("scan done");
    }
    while(questions--){
        long q;
        int cache;
        scanf("%ld",&q);
        debpri("%d",q);
        cache=find(q);//
        if(cache==-1||arr[cache]!=q){printf("-1 ");continue;}
        while(arr[cache]==q)cache--;
        printf("%d ",cache+2);
    }
    return 0;
}
int find(long q)
{
    int left=0,right=t-1;
    int t;
    if((arr[left]>q||arr[right]<q))
    {return -1;}

    //flag:
    debpri("\n left=%d\trignt=%d",left,right);
    //if(arr[left]==q){return left;debpri("left returned;");}
    //if(arr[right]==q){return right;debpri("right returned;");}
    while(left<right){
        t=(left+right)>>1;
        debpri("\n left=%d\trignt=%d",left,right);
        if(arr[t]>=q)right=t;
        else left=t+1;
        //if(arr[t]>q){right=q;goto flag;}
        //else {left=q;goto flag;}
        
    }
    return left;
}
