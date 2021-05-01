#include<iostream>
using namespace std;
int main(){
    int unhappy=0;
    int unhappyday=0;
    for(int i=1;i<=7;i++){
        int a,b;
        cin>>a>>b;
        if(a+b>8){
            if(unhappy<a+b){
                unhappy=a+b;
                unhappyday=i;
            }
        }
    }
    cout<<unhappyday<<endl;
}