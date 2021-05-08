#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[310];
int m;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+(++n));
    int last=0;
    long long cost=0;
    n--;
    while (m<=n)
    {
        cost+=(arr[m]-last)*(arr[m]-last);
        cost+=(arr[m]-arr[n])*(arr[m]-arr[n]);
        last=arr[n];
        m++,n--;
    }
    cout<<cost<<endl;
    
}