#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


int main(){
    char arr[1000];
    while(~scanf("%c",&arr[0])){
        if(arr[0]=='y'){scanf("%c%c",&arr[1],&arr[2]);
        if(arr[0]=='y'&&arr[1]=='o'&&arr[2]=='u')cout<<"we";
        else cout<<arr[0]<<arr[1]<<arr[2];}
        else cout<<arr[0];
    }
}