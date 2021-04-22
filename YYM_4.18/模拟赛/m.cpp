#include<iostream>
#include<algorithm>
using namespace std;
int arr[(int)2e5+10];
int t[(int)2e5+10];
int main(){
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        scanf("%d",t+i+1);
    }

    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++){
        arr[i-1]=t[i]+t[i-1];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=lower_bound(arr,arr+n,arr[i]+p)-(arr+i);
    }
    // cout<<judge(30,16,35)<<endl;
    cout<<cnt<<endl;
}