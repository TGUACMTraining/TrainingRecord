#include<iostream>
#include<cstdio>
using namespace std;
// #define ln 10//
#define ln 100005
int a[ln];
int b[ln];
int d[ln];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%1d",&a[i]);
        }
        b[0]=1;
        if(a[0]){
            d[0]=2;
        }else{
            d[0]=1;
        }
        for(int i=1;i<n;i++){
            switch(d[i-1]){
                case 2:
                b[i]=1-a[i];
                d[i]=1;
                break;
                case 1:
                b[i]=a[i];
                d[i]=a[i]+b[i];
                break;
                case 0:
                b[i]=1;
                d[i]=a[i]+b[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            printf("%d",b[i]);
        }cout<<endl;
    }
}