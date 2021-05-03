#include<iostream>
using namespace std;
int n;
int arr[(int)5e5+100];
long long ans;
int cache[(int)5e5+10];
int tail;
void s(int l,int r){
    if(l>=r)return ;
    int i=l,mid=(l+r)>>1,j=mid+1;
    s(i,mid);s(j,r);
    tail=0;
    while(i<=mid&&j<=r){
        if(arr[i]<=arr[j]){
            cache[tail++]=arr[i++];
        }else{
            cache[tail++]=arr[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid){
        cache[tail++]=arr[i++];
    }
    while(j<=r){
        cache[tail++]=arr[j++];
    }
    for(int k=0;k<tail;k++){
        arr[l+k]=cache[k];
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    s(0,n-1);
    cout<<ans<<endl;
}