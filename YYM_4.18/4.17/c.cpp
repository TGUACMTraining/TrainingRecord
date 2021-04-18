#include<iostream>
using namespace std;
long long arr[(int)1e3][(int)1e3];
int main(){
    long long cnt=1;
    for(int i=1;i<100;i++){
            if(i%2)
        for(int j=1;j<=i;j++){
            arr[i][j]=cnt++;
        }
        else
        for(int j=i;j>=1;j--){
            arr[i][j]=cnt++;
        }
    }
    int limit=30;
    for(int i=0;i<limit;i++){
        for(int j=0;j<limit;j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    cout<<arr[19+20][20];
    // cout<<41<<endl;
}