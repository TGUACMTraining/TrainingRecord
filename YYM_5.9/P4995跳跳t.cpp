#include<iostream>
#include<algorithm>
using namespace std;
long long n;
long long arr[310];
bool visited[310];
long long m;
long long cost(int l,int r,int to,int now){
    if(to==l&&to==r)return (arr[to]-now)*(arr[to]-now);
    if(to==l)return cost(l+1,r,r,arr[to])+(arr[to]-now)*(arr[to]-now);
    if(to==r)return cost(l,r-1,l,arr[to])+(arr[to]-now)*(arr[to]-now);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+(++n));
    cout<<cost(0,n-1,0,0)<<endl;
}