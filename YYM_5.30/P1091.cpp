#include<algorithm>
#include<iostream>
using namespace std;
void cac(int arr[],int n,int b[],int visit[]){
    int a[120];
    int t=0;
    for(int i=1;i<=n;i++){
        int k=lower_bound(a,a+t,arr[i])-a;
        a[k]=arr[i];
        if(k==t||k==t-1){
            visit[i]++;
        }
        if(k==t)t++;
        b[i]=t;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[120];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int b1[120]={0};
    int visit1[120]={0};
    int b2[120]={0};
    int visit2[120]={0};
    cac(arr,n,b1,visit1);
    reverse(arr+1,arr+1+n);
    cac(arr,n,b2,visit2);
    int mm=0;
    for(int i=1;i<=n;i++){
        int cache=b1[i]+b2[n-i+1];
        if(visit1[i]&&visit2[n-i+1])cache--;
        mm=max(cache,mm);
    }
    cout<<n-mm;
}