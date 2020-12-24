#include<stdio.h>
#include<stdlib.h>
// #define debug
#ifdef debug
#define dbg(x) {x;}
#else 
#define dbg(x) 
#endif
// void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
int cmp(const void* a,const void* b);
int main(){

    long *arr;
    int n;
    int i,p;
    scanf("%d",&n);
    arr=(long*)malloc(n*sizeof(long));
    dbg(
        printf("%p",arr)
    )
    scanf("%d",&p);
    for(i=0;i<n;i++){
        scanf("%ld",&arr[i]);
    }
    qsort(arr,n,sizeof(long),cmp);
    printf("%ld",arr[p]);
    return 0;

}
int cmp(const void* a,const void* b){
    int a_=*((long*)a);
    int b_=*((long*)b);
    return a_-b_;
}
