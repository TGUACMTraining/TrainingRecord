#include<iostream>
using namespace std;
int y(int year){
    if(year%400==0)return 1;
    if(year%100==0)return 0;
    if(year%4==0)return 1;
    return 0;
}
int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int a,b,c;
    int date[8];
    a=b=c=0;
    for(int i=0;i<4;i++){
        a*=10;
        date[i]=getchar()-'0';
        a+=date[i];
    }
    for(int i=0;i<2;i++){
        b*=10;
        date[i+4]=getchar()-'0';
        b+=date[i+4];
    }
    for(int i=0;i<2;i++){
        c*=10;
        date[i+6]=getchar()-'0';
        c+=date[i+6];
    }
    if(y(a)){
        arr[2]=29;
    }
    else arr[2]=28;

}