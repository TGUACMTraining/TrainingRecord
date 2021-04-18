#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
char map[20][20];
char result[400];
char str[400];
int tail;
struct dot
{
    int x,y;
};
int m,n;
int min_os=0x3f3f3f3f;
bool check(dot d){
    d.x--;
    d.y--;
    if(d.y<0){d.x--;d.y=n-1;}
    if(d.x<0)return true;
    else return map[d.x][d.y]=='0';
}
void r(int os){
    // cout<<endl;
    // for(int i=0;i<m*n;i++){
    //     cout<<str[i]<<" ";
    //     if((i+1)%n==0)cout<<endl;
    // }
    if(os<min_os){memcpy(result,str,sizeof(str));min_os=os;}
    else if(strcmp(result,str)>0)memcpy(result,str,sizeof(str));
}
void change(int x,int y){
    if(x>=0&&x<m&&y>=0&&y<n){
        switch (map[x][y])
        {
        case '1':
            map[x][y]='0';
            break;
        
        default:
            map[x][y]='1';
            break;
        }
    }
}
void flip(dot d){
    change(d.x,d.y);
    change(d.x+1,d.y);
    change(d.x,d.y+1);
    change(d.x-1,d.y);
    change(d.x,d.y-1);
}
dot nd(dot d){
    d.y++;
    if(d.y>=n){d.y=0;d.x++;}
    return d;
}
void dfs(dot d,int os){
    if(os>min_os)return;
    if(!check(d))return;
    if(d.x==m&&d.y==0){
        int flag=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]=='1'){
                    flag=0;
                    goto out;
                }
            }
        }
        out:
        if(flag){
            r(os);
        }
    }
    for(int i=0;i<2;i++){
        str[tail++]=i+'0';
        if(i==1)flip(d);
        dfs(nd(d),os+i);
        tail--;
        if(i==1)flip(d);
    }
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    dfs({0,0},0);
    if(result[0])
    for(int i=0;i<m*n;i++){
        cout<<result[i]<<" ";
        if((i+1)%n==0)cout<<endl;
    }else cout<<"IMPOSSIBLE"<<endl;
}