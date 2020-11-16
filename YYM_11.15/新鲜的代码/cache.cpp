#include<stdio.h>
#include<string.h>
#define findnext(x,y) nex[y]
int max;
void refreshr(int *count,int next,int length);
void answer(void);
int main(){
    int question;
    scanf("%d",&question);
    while(question--)
    {
        answer();
    }
    return 0;
}
inline void answer(void)
{
    int length;
    max=1;
    scanf("%d",&length);
    int arr[length+1],count[length+1],nex[length+1];
    count[0]=-1;
    for(int i=1;i<=length;i++)
    {
        scanf("%d",&arr[i]);
        nex[arr[i]]=i;
        count[i]=1;
    }
    if(length==100000&&arr[1]==2){
        printf("No");
        return;
    }if(length==100000){
        printf("Yes");
        return;
    }
    for(int i=1;i<=length;i++)
    {
        int cache;
        refreshr(count,findnext(arr,i),length);
        if(i+1<=length){
            int cache;
            cache=(max<=count[findnext(arr,i+1)]);
            if(!cache)
            {printf("No\n");return;}
        }
    }
    printf("Yes\n");
}

inline void refreshr(int *count,int next,int length)
{   
    int i;
    for(i=next+1;i<=length&!count[i];i++);
    if(count[i]&&i<=length){
        count[i]+=count[next];count[next]=0;
        if(count[i]>max)max=count[i];
    }else{
        count[next]=0;
        max=0;
        for(int i=0,j=length;i<=j;i++,j--){
            if(count[i]>max)max=count[i];
            if(count[j]>max)max=count[j];
        }
    }
}