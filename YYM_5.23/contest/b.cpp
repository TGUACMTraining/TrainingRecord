#include<algorithm>
#include<iostream>
using namespace std;
int arr[(int)3e5+10];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<3*n;i++){
        scanf("%d",arr+i);
    }
    sort(arr,arr+n*3);
    long long ans=0;
    for(int i=3*n-1,p=0;p<n;p++){
        i--;
        ans+=arr[i--];
    }
    printf("%lld",ans);
}