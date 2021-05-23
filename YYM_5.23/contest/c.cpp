#include<iostream>
using namespace std;
long long ans;
int arr[(int)3e5+10];
int atp[(int)3e5+10];
void merg(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    merg(l,mid);
    merg(mid+1,r);
    int x,y;
    x=l,y=mid+1;
    int t=0;
    while(x<=mid&&y<=r){
        if(arr[x]<=arr[y]){
            atp[t++]=arr[x++];
        }else{
            ans+=mid-x+1;
            atp[t++]=arr[y++];
        }
    }
    while(x<=mid){
        atp[t++]=arr[x++];
    }
    while(y<=r){
        atp[t++]=arr[y++];
    }
    for(int i=l;i<=r;i++){
        arr[i]=atp[i-l];
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<(int)3e5+10;i++){
        arr[i]=i;
    }
    while(m--){
        int tmp;
        scanf("%d",&tmp);
        arr[tmp]^=arr[tmp+1];
        arr[tmp+1]^=arr[tmp];
        arr[tmp]^=arr[tmp+1];
    }
    for(int i=1;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[n]);
    merg(1,n);
    printf("%lld",ans);
}