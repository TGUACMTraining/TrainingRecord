#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
    int arr[100020]={0};
    int n;
    int a,b;
    do{
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            arr[a]++;
            arr[b+1]--;
        }
        //
        if(n) cout<<arr[1];
        for(int i=2;i<=n;i++){
            arr[i]+=arr[i-1];
            // printf("%d ",arr[i]);
            cout<<" "<<arr[i];
        }
        if(n) printf("\n");
        memset(arr,0,100020*sizeof(int));
    }while(n);
    return 0;
}