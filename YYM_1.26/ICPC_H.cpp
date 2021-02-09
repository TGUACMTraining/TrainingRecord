#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int _map[110][110];
int x_max;
int y_max;
void print_map(){
    //     cout<<endl;
    //     cout<<endl;

    // for(int i=0;i<y_max;i++){
    //     for(int j=0;j<x_max;j++){
    //         printf("%2d",_map[j][i]);
    //     }
    //     cout<<endl;
    // }
    //     cout<<endl;
    //     cout<<endl;

}
void color(int x1,int x2,int y){
    if(x1>x2){
        swap(x1,x2);
    }
    for(;x1<=x2;x1++){
        _map[x1][y]=x2;
    }
}
    int _max=-1;
    int at;
int judge(int x){
    int n=0;
    _max=-1;
    for(int i=0;i<y_max;i++){
        if(_map[x][i]!=-1){
            n++;
            if(_map[x][i]>_max){
                _max=_map[x][i];
                at=i;
            }
        }
    }
    return n;
}
int killed=0;
void kill(int x,int y){
    int stop=_map[x][y];
    while(_map[x][y]==stop){
        _map[x++][y]=-1;
    }
    killed++;
    print_map();
}

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(_map,-1,sizeof(_map));
        x_max=y_max=0;
        killed=0;
        int points;
        int power;
        cin>>points;
        cin>>power;
        int x1,x2,y;
        while(points--){
            scanf("%d%d%d%*d",&x1,&y,&x2);
            x_max=max(max(x1,x2),x_max);
            y_max=max(y_max,y);
            color(x1,x2,y);
        }
        x_max++;
        y_max++;
        print_map();
        for(int i=0;i<110;i++){
            if(judge(i)>power) kill(i--,at);
        }
        cout<<killed<<endl;
    }
}