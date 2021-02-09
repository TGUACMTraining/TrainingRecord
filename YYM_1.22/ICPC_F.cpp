#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int n,m;
    int time=0;
    while(cin>>n>>m,n&&m){ 
    n*=m;
    int arr[1000];
    double helper[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    arr[n]=0x3f3f3f3f;
    helper[0]=arr[0];
    for(int i=1;i<=n;i++){
        helper[i]=arr[i]+helper[i-1];
    }
    double water;
    cin>>water;
    double height;
    int i=0;
    for(;i<n;i++){
        helper[i]/=(i+1);
        height= water/(i+1)/100+helper[i];
        if(height<arr[i+1])break;
    }
    printf("Region %d\n",++time);
    printf("Water level is %.2f meters.\n%.2f percent of the region is under water.\n",height,(i+1.0)/n*100);
    }
}