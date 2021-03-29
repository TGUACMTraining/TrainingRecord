#include<iostream>
using namespace std;
int f[6];
int g[6];
int result[6];
void dp(){
    for(int i=0;i<6;i++){//总空间
        for(int j=0;j<=i;j++){//分配给第一个物品
            result[i]=max(result[i],f[j]+g[i-j]);
        }
    }
}
int main(){
    for(int i=0;i<6;i++){
        cin>>f[i];
    }
    for(int i=0;i<6;i++){
        cin>>g[i];
    }
    dp();
    for(int i=0;i<6;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}