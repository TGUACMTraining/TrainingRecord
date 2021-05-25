#include<iostream>
using namespace std;
const int item_lim=30;
const int money_lim=30010;
int cost [item_lim],imp[item_lim],expect[item_lim];
int res[item_lim][money_lim];
int main(){
    int it,mo;
    cin>>mo>>it;
    for(int i=1;i<=it;i++){
        cin>>cost[i]>>imp[i];
        expect[i]=cost[i]*imp[i];
    }
    for(int ii=1;ii<=it;ii++){
        for(int cc=1;cc<=mo;cc++){
            res[ii][cc]=res[ii-1][cc];
            if(cc-cost[ii]>=0){
                res[ii][cc]=max(res[ii][cc],res[ii-1][cc-cost[ii]]+expect[ii]);
            }
        }
    }
    cout<<res[it][mo];
}