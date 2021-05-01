#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[110];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[k]==arr[i]+arr[j])
                {
                    cnt++;
                    goto flag;
                }
            }
        }flag:;
    }
    cout<<cnt;
}