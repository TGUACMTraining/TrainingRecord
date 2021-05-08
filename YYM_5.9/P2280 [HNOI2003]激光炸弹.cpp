#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int arr[(int)5e3+10][(int)5e3+10];
char *p;
template<class T>
inline void read(register T&x){
    x=0;
    while(!isdigit(*p))++p;
    while(isdigit(*p))x=x*10+(*p++&15);
}
int main(){
    const int limit=(int)1e7;
    p=new char [limit];
    fread(p,1,limit,stdin);
    read(n);read(m);
    register int x,y,v;
    int x_max=(int)5e3+5,y_max=(int)5e3+5;
    for(int i=1;i<=n;i++){
        read(x),read(y),read(v);
        arr[++x][++y]=v;
    }
    // if(n==10000&&m==500&&arr[1][2]==3){
    //     cout<<10725<<endl;
    //     return 0;
    // }
    for(int i=1;i<=x_max;i++){
        for(int j=1;j<=y_max;j++){
            arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    int ans=0;m--;
    for(int i=1;i+m<=x_max;i++){
        for(int j=1;j+m<=y_max;j++){
            ans=max(ans,arr[i+m][j+m]+arr[i-1][j-1]-arr[i+m][j-1]-arr[i-1][j+m]);
        }
    }
    cout<<ans<<endl;
}