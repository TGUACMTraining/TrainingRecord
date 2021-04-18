#include<iostream>
using namespace std;
int main(){
    int day=6;
    int date=1;
    int cnt=0;
    bool jl;
    int tail=0;
    int arr[]={31,29,31,30,31,30,31,31,30,31,30,31};
    while(1){
        jl==false;
        day%=7;
        if(date==arr[tail]){tail++;date=1;}
        if(day==1)jl=true;
        if(date==1)jl=true;
        if(jl)cnt++;
        if(tail==9&&date==1)break;
        cnt++;
        day++;
        date++;
    }cout<<cnt<<endl;
}