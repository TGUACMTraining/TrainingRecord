#include<bits/stdc++.h>
using namespace std;
#define max 45
int main(){
    // int arr[max]={1,1};
    // for(int i=0;i<max-2;i++){
    //     arr[i+2]=arr[i]+arr[i+1];
    // }
    int n;
    cin>>n;
    int numbers[100000];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers,numbers+n);
    int flag=0;
    for(int i=0;i<n-2;i++){
        if(numbers[i]+numbers[i+1]>numbers[i+2]){
            flag=1;
            break;
        }
    }if(flag){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
    return 0;
}