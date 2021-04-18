#include<iostream>
using namespace std;
int fg[7];
enum {a,b,c,d,e,f,g};
int next[7][4]={
    {b,f,-1,-1,},
    {a,g,c,-1},
    {b,g,d,-1},
    {e,c,-1,-1},
    {d,g,f,-1},
    {a,g,e,-1},
    {}
}
int main(){
    for(int i=1;i<1<<8;i++){
        for(int j=0;j<7;j++){
            fg[j]=i&1<<j;
        }
    }
}