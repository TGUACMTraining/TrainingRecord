#include<iostream>
using namespace std;
int a[4];
int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        int cache;
        a[1]=a[2]=a[3]=0;
        for(int i=0;i<m;i++){
            cin>>cache;
            a[cache]++;
        }
        cout<<a[1]+a[3]<<endl;
    }
}