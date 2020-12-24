#include<stdio.h>
#include<stdlib.h>
// #define debug
#ifdef debug
#define dbg(x) {x;}
#define printall \
for(int i=0;i<n;i++){\
    printf("%d ",arr[i]);\
}\
printf("\n");
#else
#define dbg(x)
#define printall
#endif
    int n;
void InsertSort(long arr[], int m, int n);
void sort(long* ,int,int);
void middle(long*arr,long a,long b,long c);
int main(){

    long *arr;
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
    sort(arr,0,n-1);
    printf("%ld",arr[p]);
    dbg(
        printall
    )
    return 0;

}
void sort(long* arr,int l,int r){
    dbg(
        printf("l=%d r=%d\n",l,r);
    )
    printall
    if(l<r){
        if(r-l+1<10){
            InsertSort(arr,l,r);
            return;
        }
        int left=l,right=r;
        middle(arr,l,r,(l+r)>>1);
        printall
        long cache=arr[l];
        dbg(
            printf("cache=%d\n",cache)
        )
        while(l<r){
            while(l<r&&arr[r]>=cache){
                r--;
            }
            arr[l]=arr[r];
            while(l<r&&arr[l]<=cache){
                l++;
            }
            arr[r]=arr[l];
        }
        arr[l]=cache;
        printall
        sort(arr,left,l-1);
        sort(arr,r+1,right);
    }
}

void middle(long*arr,long a,long b,long c){
    int p=(int)(arr[a]>=arr[b])<<2;
    p+=(int)(arr[b]>=arr[c])<<1;
    p+=(int)(arr[c]>=arr[a]);
    switch(p){
        int cache;
        case 5:
        case 2:
            return;
        case 1:
        case 6:
            cache=arr[a];
            arr[a]=arr[b];
            arr[b]=cache;
            return;
        case 3:
        case 4:
        case 7:
        case 0:
            cache=arr[a];
            arr[a]=arr[c];
            arr[c]=cache;
            return;
        
    }
    // if(a<c){
    //     return middle(c,b,a);
    // }
    // if(a>=b&&b>=c){
    //     return b;
    // }else return middle(b,c,a);
}

void InsertSort(long arr[], int m, int n)
{
	int i, j;
	long temp; 
	for(i = m+1; i <= n; i++)
	{
		temp = arr[i];
		for(j = i-1; (j >= m)&&(arr[j] > temp); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
 
