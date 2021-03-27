#include<iostream>
using namespace std;
int arr[50];
int max_;
int res;
int main(){
    int T;
    int cache;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            res=0;
            arr[i]=100-arr[i];
            res+=arr[i]*arr[i];
            arr[i]=100-arr[i];
            if(res>max_)max_=res;
            if(m>1)
            for(int j=0;j<n;j++){
                if(arr[j]<arr[i]){
                    cache=(arr[i]-arr[j]);
                    res+= cache*cache;
                    if(res>max_)max_=res;
                    res-=cache*cache;
                }
            }
        }
        cout<<max_<<endl;
        max_=0;
    }
}