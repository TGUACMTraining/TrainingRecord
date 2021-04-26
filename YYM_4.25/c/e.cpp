#include<iostream>
using namespace std;
struct co{
    int hours;
    int spirit;
}cost[110];
int coin[110];
int getcoin[110][310][110];//time spirit;
int n;
int h;
int s;

int main(){
    cin>>n>>h>>s;    
    for(int i=1;i<=n;i++){
        cin>>coin[i]>>cost[i].hours>>cost[i].spirit;
    }
    for(int i=1;i<=n;i++){
        for(int tm=1;tm<=h;tm++){
            for(int sprt=1;sprt<=s;sprt++){
                if(cost[i].hours<=tm){
                    if(cost[i].spirit<=sprt){
                        getcoin[i][tm][sprt]=getcoin[i-1][tm-cost[i].hours][sprt-cost[i].spirit]+coin[i];

                    }
                }
                getcoin[i][tm][sprt]=max(getcoin[i][tm][sprt],getcoin[i-1][tm][sprt]);
            }
        }
    }
    cout<<getcoin[n][h][s]<<endl;
}