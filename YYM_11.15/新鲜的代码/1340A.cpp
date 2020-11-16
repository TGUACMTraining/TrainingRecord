#include<stdio.h>
#include<string.h>
const int debug=0;
int isbiggist(int *count,int length,int next);
void refreshcount(int *r,int *count,int length);
void refreshr(int *count,int *r,int length);
int findnext(int *arr,int n);
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
void answer(void)
{
    int length;
    scanf("%d",&length);
    int arr[length+1],r[length+1],count[length+1];
    count[0]=-1;r[0]=-1;
    for(int i=1;i<=length;i++)
    {
        scanf("%d",&arr[i]);
        r[i]=i;
        count[i]=1;
    }
    for(int i=1;i<=length;i++)
    {
        int cache;
        count[(cache=findnext(arr,i))]=0;
        refreshr(count,r,length);
        // if(debug){
        //     printf("\n\t\ti %d",i);
        //     printf("\n\t\ti:");
        //     for(int i=0;i<length+1;i++){
        //         printf("%d\t",i);
        //     }
        // }
        // if(debug){
        //     printf("\n\t\tr:");
        //     for(int i=0;i<length+1;i++){
        //         printf("%d\t",r[i]);
        //     }
        // }
        refreshcount(r,count,length);
        // if(debug){
        //     printf("\n\t\tcount:");
        //     for(int i=0;i<length+1;i++){
        //         printf("%d\t",count[i]);
        //     }
        //     // printf("\n");
        // }
        if(i+1<=length){
            int cache;
            cache=isbiggist(count,length,findnext(arr,i+1));
            // if(debug){
            //     printf("\n\t\tnext:%d\n",findnext(arr,i+1));
            //     printf("\t\treturn%d\n",cache);            
            // }
            if(!cache)
            {printf("No\n");return;}
        }
    }
    printf("Yes\n");
}
inline int isbiggist(int *count,int length,int next){
    for(int i=1;i<=length;i++){
        if(count[i]>count[next]){return 0;}
    }
    return 1;
}
inline int findnext(int *arr,int n)
{
    int t=0;
    while(arr[t]!=n)t++;
    return t;
}
inline void refreshr(int *count,int *r,int length)
{
    for(int i=1;i<=length;i++){
        if(!count[i])//更新开始
        {   
            int j;
            for(j=i;j<=length;j++)
            {
                if(count[j])break;
            }
            if(j<=length)r[i]=j;else r[i]=0;
        }
    }
}
inline void refreshcount(int *r,int *count,int length)
{
    for(int i=0;i<=length+1;i++)
    {
        count[i]=0;
    }
    for(int i=1;i<=length;i++){
        count[r[i]]++;
    }
    count[0]=0;
}