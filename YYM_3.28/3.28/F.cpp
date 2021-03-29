#include<iostream>
using namespace std;
int num[3]={1,2,5};
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int cnt=0;
        for(int i=0;i<=n&&i*num[2]<=m;i++){
            for(int j=0;j+i<=n&&j*num[1]<=m-i*num[2];j++){
                int k=m-i*num[2]-j*num[1];
                if(i+j+k==n)cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}