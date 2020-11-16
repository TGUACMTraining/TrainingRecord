#include<iostream>
#include<stdio.h>
using namespace std;
void sor(int a[],int l,int r);
int next(int arr[],int length);
int main(){
    int n;
    int i=0;
    while(scanf("%d",&n)!=EOF)
    {
        //if(i==0){i++;}else printf("\n");
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int m;
        scanf("%d",&m);
        m--;
        while(m--){
            next(arr,n);
        }
        cout<<arr[0];
        for(int i=1;i<n;i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
int next(int arr[],int length){
    int cache;int left;int right;right=length-1;
    while(arr[right]<arr[right-1]){if(right>1){right--;}else return 0;}left=right-1;
    while(right<length){if(arr[right]<=arr[left]){break;}right++;}right--;
    cache=arr[left];arr[left]=arr[right];arr[right]=cache;sor(arr,left+1,length-1);
    return 1;
}
void sor(int a[],int l,int r)
{
	if(l>=r)return;
	int i=l-1,j=r+1;int x=a[(l+r)/2];
	while(i<j){i++,j--;while(a[i]<x)i++;while(a[j]>x)j--;if(i<j){int m=a[i];a[i]=a[j];a[j]=m;}}
	sor(a,l,j);sor(a,j+1,r);
}
