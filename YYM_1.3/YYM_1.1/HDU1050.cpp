#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        int arr[210];
        memset(arr,0,sizeof(arr));
        int big,small;
        for(int i=0;i<n;i++){
            cin>>big>>small;
            if(big<small){
                big=(big+1)/2;
                small=(small+1)/2;
                arr[small+1]--;
                arr[big]++;
            }
            else{
                big=(big+1)/2;
                small=(small+1)/2;
                arr[big+1]--;
                arr[small]++;
            }
        }
        int time=0;
        int share=0;
        for(int i=1;i<210;i++){
            share+=arr[i];
            if(time<share){
                time=share;
            }
        }
        time*=10;
        cout<<time<<endl;
    }
    return 0;
}