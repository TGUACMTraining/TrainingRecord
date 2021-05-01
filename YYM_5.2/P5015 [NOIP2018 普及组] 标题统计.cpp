#include<iostream>
using namespace std;
int main(){
    int cnt=0;
    int cache;
    while((cache=getchar())!=EOF){
        if(cache!=' '&&cache!='\n')cnt++;
    }
    cout<<cnt;
}