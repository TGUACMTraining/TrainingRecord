#include<iostream>
using namespace std;
int arr[(int)1e5+10];
int n;
void s(int l,int r){
    int mid=arr[(l+r)/2];
    int ll=l;
    int rr=r;
    do{
        while(arr[l]<mid)l++;
        while(arr[r]>mid)r--;
        if(l<=r){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }while(l<=r);
    if(ll<r)s(ll,r);
    if(l<rr)s(l,rr);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    s(0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}