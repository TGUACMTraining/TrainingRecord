#include<iostream>
using namespace std;
int arr[7][7];
int main(){
    arr[1][5]=1;
    arr[1][3]=1;
    arr[2][5]=1;
    arr[3][3]=1;
    arr[4][5]=1;
    for(int i=0;i<7;i++){
        cout<<i<<" ";
    }cout<<endl;
    for(int i=1;i<7;i++){
        cout<<i<<" ";
        for(int j=1;j<7;j++){
            cout<<(arr[i][j]?"1":" ")<<" ";
        }cout<<endl;
    }
    cout<<endl;
    for(int k=1;k<7;k++)
    for(int i=1;i<7;i++){
        for(int j=1;j<7;j++){
            arr[i][j]=arr[i][j]||(arr[i][k]&&arr[k][j]);
        }
    }
    for(int i=0;i<7;i++){
        cout<<i<<" ";
    }cout<<endl;
    for(int i=1;i<7;i++){
        cout<<i<<" ";
        for(int j=1;j<7;j++){
            cout<<(arr[i][j]?"1":" ")<<" ";
        }cout<<endl;
    }
    for(int i=1;i<7;i++){
        for(int j=1;j<7;j++){
            if(arr[i][j])printf("<%d,%d>\n",i,j);
        }
    }
}