#include<iostream>
using namespace std;
int main(){
    int cost[3];
    int num[3];
    int buy[3];
    int total;
    cin>>total;
    int money=0x3f3f3f3f;
    for(int i=0;i<3;i++){
        cin>>num[i]>>cost[i];
        buy[i]=total/num[i]+(total%num[i]?1:0);
        buy[i]=buy[i]*cost[i];
        money=min(buy[i],money);
    }
    cout<<money;
}