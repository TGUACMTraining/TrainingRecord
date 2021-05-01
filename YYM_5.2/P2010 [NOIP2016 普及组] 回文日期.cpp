#include<iostream>
using namespace std;
struct date{
    int year;
    int month;
    int day;
};
int days[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31},
};
int r(int year){
    if(year%400==0)return 1;
    if(year%100==0)return 0;
    if(year%4==0)return 1;
    return 0;
}
date next_date(date d){
    d.day++;
    if(d.day==days[r(d.year)][d.month]+1){d.day=1;d.month++;}
    if(d.month==13){
        d.year++;
        d.month=1;
    }
    return d;
}
date int_to_date(int i){
    date d;
    d.day=i%100;
    i/=100;
    d.month=i%100;
    i/=100;
    d.year=i;
    return d;
}
bool j(date d){
    char s[10];
    sprintf(s,"%04d%02d%02d",d.year,d.month,d.day);
    return s[0]==s[7]&&s[1]==s[6]&&s[2]==s[5]&&s[3]==s[4];
}
int main(){
    int from,to;
    cin>>from>>to;
    date d=int_to_date(from);
    date stop=next_date(int_to_date(to));
    int cnt=0;
    for(;d.year!=stop.year||d.month!=stop.month||d.day!=stop.day;d=next_date(d)){
        if(j(d))cnt++;
    }
    cout<<cnt;
}