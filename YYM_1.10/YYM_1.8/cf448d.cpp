#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,k;
unsigned long long close(unsigned long long  x){
    unsigned long long ans=0;
    for(int i=1;i<=n;i++){
        if(x>i*m)ans+=m;
        else ans+=x/i;
    }
    return ans;
}
int main(){
    int index=0;
    cin>>n>>m>>k;
    unsigned long  long  l=0,r;
    unsigned long  long mid;
    r=n*m;
    unsigned long long  a;
    while(r-l>5){
        mid=(l+r)/2;
        a=close(mid);
        if(a>k)r=mid;
        else if(a<k)l=mid;
        else {l=mid-2,r=mid+2;break;}
    }
    if(a!=k){
    unsigned long long arr1[7];
    unsigned long long arr2[7];
    while (l<=r)
    {
        arr1[index]=close(l);
        arr2[index++]=l;
        l++;
    }
    cout<<arr2[lower_bound(arr1,arr1+index,k)-arr1];
    }
    else{
        while(close(--mid)==k);
        mid++;
        cout<<mid;
    }
}