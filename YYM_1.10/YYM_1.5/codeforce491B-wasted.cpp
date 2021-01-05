#include<bits/stdc++.h>
#define ca 100500
using namespace std;
typedef struct DOT{
    int x;
    int y;
    int xay;
    int xmy;
       
    DOT operator=(DOT &a){
        x=a.x;
        y=a.y;
        return *this;
    }
}dot;
int main(){
    int n,m,c,h;
    dot restrunt[ca];
    int length[ca]={0};
    dot hotel[ca];
    cin>>n>>m;
    cin>>c;
    int xaymax=0;
    int xmymax=n>m?m-n:n-m;
    int xaymin=n+m;
    int xmymin=n>m?n-m:m-n;
    dot cache;
    for(int i=0;i<c;i++){
        cin>>hotel[i].x>>hotel[i].y;
        hotel[i].xay=hotel[i].x+hotel[i].y;
        hotel[i].xmy=hotel[i].x-hotel[i].y;
        if(hotel[i].xay>xaymax)xaymax=hotel[i].xay;
        else if(hotel[i].xay<xaymin)xaymin=hotel[i].xay;
        if(hotel[i].xmy>xmymax)xmymax=hotel[i].xmy;
        else if(hotel[i].xmy<xmymin)xmymin=hotel[i].xmy;
    }
    dot judge[ca];
    int begin;int end;
    begin=end=0;
    for(int i=0;i<c;i++){
        if(hotel[i].xay==xaymax){judge[begin++]= hotel[i];continue;}
        if(hotel[i].xay==xaymin){judge[begin++]= hotel[i];continue;}
        if(hotel[i].xmy==xmymax){judge[begin++]= hotel[i];continue;}
        if(hotel[i].xmy==xmymin){judge[begin++]= hotel[i];continue;}
    }
    cin>>h;
    int minlength=m+n;
    int out;
    int a;
    for(int i=0;i<h;i++){
        cin>>cache.x>>cache.y;
        restrunt[i]=cache;
        for(int  index=0;index!=begin;index++){
            a=abs(judge[index].x-restrunt[i].x)+abs(judge[index].y-restrunt[i].y);
            if(a>length[i])length[i]=a;
        }
        if(length[i]<minlength){
            minlength=length[i];
            out=i;
        }
    }
            cout<<length[out]<<endl<<out+1<<endl;
    return 0;
}