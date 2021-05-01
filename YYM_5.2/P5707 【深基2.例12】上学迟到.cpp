#include<iostream>
using namespace std;
int main(){
    int s,v;
    int time;
    time=8*60-10;
    cin>>s>>v;
    time=time-s/v;
    time=time-((s%v)?1:0);
    if(time<0)time+=60*24;
    printf("%02d:%02d",time/60,time%60);
}