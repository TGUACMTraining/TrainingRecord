#include<stdio.h>
#include<math.h>
// #define debug
#ifdef debug
#define dbg(x) {x;}
#else 
#define dbg(x)
#endif
long long arr[20]={0};
long long arr_[20];
int n;
void scan(void);
void print(void);
void sort(int l,int r);
int main(){
    scan();
    sort(0,n-1);
    print();
    return 0;
}
void scan (void){
    scanf("%d",&n);
    dbg(
        printf("n= %d\n",n);
    )
    int i;
    for(i=0;i<n;i++){
        scanf("%lld",&arr_[i]);
        int len=(int)log10(arr_[i]);
        len++;
        int go=9-len;
        dbg(
            printf("len=%d go=%d\n",len,go);
        )
        while(go>0){
            arr[i]+=arr_[i]*(int)pow(10,go);
            go-=len;
        dbg(printf("arr[i]=%d go=%d\n",arr[i],go))
        }
        if(go<=0)
            arr[i]+=(int)(arr_[i]*pow(10,go));
        dbg(
            printf("get %lld\n",arr[i]);
        )
    }
}
void print(void){
    for(int i=0;i<n;i++){
        printf("%lld",arr_[i]);
    }
}
void sort(int l,int r){
    if(l==r)return;
    if(l>r)return;
    long long cache=arr[l];
    long long cache_=arr_[l];
    int left=l;
    int right=r;
    dbg(
        printf("left=%d\nright=%d\n",left,right);
    )
    while(l<r){
        while(l<r&&arr[r]<=cache){
            r--;
        }
        dbg(
            printf("catch r=%d\n",r);
        )
        arr[l]=arr[r];
        arr_[l]=arr_[r];
        while(l<r&&arr[l]>=cache){
            l++;
        }
        dbg(
            printf("catch l=%d\n",l);
        )
        arr[r]=arr[l];
        arr_[r]=arr_[l];
    }
    arr[l]=cache;
    arr_[l]=cache_;
    sort(left,l-1);
    sort(r+1,right);
}