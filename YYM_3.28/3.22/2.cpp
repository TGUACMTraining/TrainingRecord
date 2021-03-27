#include<iostream>
#include<cstdio>
using namespace std;
double arr[1200];
void build(){
    int fuhao=1;
    for(int i=1;i<1100;i++){
        arr[i]=arr[i-1]+1.0/i*fuhao;
        fuhao=-fuhao;
    }
}
int main(){
    int n;
    build();
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        printf("%.2f\n",arr[m]);
    }
}