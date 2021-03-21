#include<iostream>
#include<cstdio>
using namespace std;
const int limit=(int)1E8;
bool notprime[limit+10];
int prime[(int)limit/13+5000];
int tail=0;
char* prime_month_day[]={"0103","0107","0113","0131","0211","0223","0229","0307","0311","0313","0317","0331","0419","0503","0523","0607","0613","0617","0619","0719","0811","0823","0829","0907","0911","0919","0929","1013","1019","1031","1103","1117","1123","1129","1213","1217","1223","1229","1231"};
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
long long ans;
char cache_date[9];
int c_d_m(int i){
    int flag=1;
    for(int j=4;j<8;j++){
        if(cache_date[j]=='-')continue;
        else if(cache_date[j]==prime_month_day[i][j-4])continue;
        else {flag=0;break;}
    }
    return flag;
}
bool runnian(int year){
     int a;
    if(year%400==0)a=1;
    else
    {
        if(year%4==0&&year%100!=0)a=1;
        else a=0;
    }
    return a;
}
void s_y(int i,int j,int last){
    if(j==4){
        if(last==0)return;
        if(i==6&&!runnian(last))return;
        for(int index=0;index<4;index++)
        last=last*10+prime_month_day[i][index]-'0';
        if(notprime[last]==0)ans++;
        return ;
    }
    if(cache_date[j]=='-')
    for(int plus=0;plus<10;plus++){
        s_y(i,j+1,10*last+plus);
    }
    else{
        s_y(i,j+1,10*last+cache_date[j]-'0');
    }
}
void s_d_m(){
    ans=0;
    for(int i=0;i<39;i++){
        if(c_d_m(i))
        s_y(i,0,0);
    }
}
int main(){
    build();
    int n;
    cin>>n;
    while(n--){
        scanf("%s",cache_date);
        s_d_m();
        cout<<ans<<endl;
    }

}