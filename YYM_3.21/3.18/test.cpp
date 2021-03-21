#include<iostream>
using namespace std;
const int limit=(int)1E8;
bool notprime[limit+10];
int prime[(int)limit/13+5000];
int tail=0;
void build(){
    notprime[0]=notprime[1]=1;
    for(int i=2;i<=limit;i++){
        if(!notprime[i])prime[tail++]=i;
        for(int j=0;j<tail;j++){
            if(prime[j]*i>limit)break;
            notprime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
bool judge(int month_day){
    int month=month_day/100;
    int day=month_day%100;
    if(notprime[day])return false;
    if(month>12||month==0||day==0||day>31)return false;
    if(month==2){if(day>29)return false;}else return true;
    int judge31[13]={0,1,0,1,0,1,0,1,1,0,1,0,1};
    if(day>30+judge31[month])return false;
    else return true;
}
int main(){
    build();
    for(int i=0;prime[i]<=1231;i++){
        if(judge(prime[i]))cout<<prime[i]<<endl;
    }
}