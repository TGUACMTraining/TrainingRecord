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
int inf=0x7fffffff;
int main(){
    int n,m,C,h;
    dot restrunt[ca];
    int length[ca]={0};
    dot hotel;
    cin>>n>>m;
    cin>>C;
    int xaymax=-inf;
    int xmymax=-inf;
    int xaymin=inf;
    int xmymin=inf;
    dot cache;
    for(int i=0;i<C;i++){
        cin>>hotel.x>>hotel.y;
        hotel.xay=hotel.x+hotel.y;
        hotel.xmy=hotel.x-hotel.y;
        if(hotel.xay>xaymax)xaymax=hotel.xay;
        if(hotel.xay<xaymin)xaymin=hotel.xay;
        if(hotel.xmy>xmymax)xmymax=hotel.xmy;
        if(hotel.xmy<xmymin)xmymin=hotel.xmy;
    }
    cin>>h;
    int minlength=m+n;
    int out;
    int a,b,c,d;
    for(int i=0;i<h;i++){
        cin>>restrunt[i].x>>restrunt[i].y;
        restrunt[i].xay=restrunt[i].x+restrunt[i].y;
        restrunt[i].xmy=restrunt[i].x-restrunt[i].y;
        {
            a=abs(xaymax-restrunt[i].xay);
            b=abs(xaymin-restrunt[i].xay);
            c=abs(xmymax-restrunt[i].xmy);
            d=abs(xmymin-restrunt[i].xmy);
            length[i]=max(max(a,b),max(c,d));
        }
        if(length[i]<minlength){
            minlength=length[i];
            out=i;
        }
    }
            cout<<length[out]<<endl<<out+1<<endl;
    return 0;
}