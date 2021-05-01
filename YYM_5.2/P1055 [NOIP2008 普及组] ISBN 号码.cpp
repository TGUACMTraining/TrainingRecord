#include<iostream>
using namespace std;
int main(){
    int arr[9];
    int ok=0;
    char cache;
    for(int i=0;i<9;i++){
        if(i==1||i==4||i==9){
            getchar();
        }
        arr[i]=getchar()-'0';
    }
    for(int i=0;i<9;i++){
        ok+=arr[i]*(i+1);
        ok%=11;
    }
    getchar();
    if(ok==10)ok='X';
    else{
        ok+='0';
    }
    if(ok==getchar()){
        cout<<"Right";
    }
    else{
        for(int i=0;i<9;i++){
            if(i==1||i==4||i==9){
                cout<<"-";
            }
            cout<<arr[i];
        }
        cout<<"-";
        printf("%c",ok);
    }
}