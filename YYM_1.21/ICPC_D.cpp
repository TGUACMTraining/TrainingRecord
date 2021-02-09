#include<iostream>
#include<stdio.h>
using namespace std;
int m[1010][1010];
int main(){
    int n;
    while(cin>>n,n){
        int flag=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&m[1][i]);
        }
        for(int i=2;i<=n;i++){
            cin>>m[i][1];
            for(int j=2;j<=n;j++){
                scanf("%d",&m[i][j]);
                if(m[i][j]+m[i-1][j-1]!=m[i-1][j]+m[i][j-1]){flag=0;}
            }
        }
        if(flag){
            cout<<"homogeneous"<<endl;
        }else{
            cout<<"not homogeneous"<<endl;
        }
    }
}  