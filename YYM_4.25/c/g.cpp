#include<iostream>
using namespace std;
int arr[2][100010];
int tail[2];
int main(){
    ios::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    k++;
    int mode=0;
    for(int i=0;i<n;i++){
        arr[mode][i]=i+1;
    }tail[mode]=n;
    while(1){
        int pre=mode;
        mode=(mode+1)%2;
        tail[mode]=0;
        for(int i=0;i<tail[pre];i++){
            if(i%k==0){
                cout<<arr[pre][i]<<" ";
            }else{
                arr[mode][tail[mode]++]=arr[pre][i];
            }
        }
        if(tail[mode]==0)break;
    }
}