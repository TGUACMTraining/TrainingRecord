#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
char map[50][50];
int m,n;
struct dot
{
    int x,y;
};
void flip(int x,int y ){
    if(x>=0&&y>=0&&x<m&&y<n){
        switch (map[x][y])
        {
        case '0':
            map[x][y]='1';
            break;
        
        default:
            map[x][y]='0';
            break;
        }
    }
}
void change(int mode,dot d){
    switch (mode)
    {
    case 1:
        flip(d.x,d.y);
        flip(d.x+1,d.y);
        flip(d.x,d.y+1);
        flip(d.x-1,d.y);
        flip(d.x,d.y-1);
        break;
    
    default:
        break;
    }
}
char str[2500];
char result[2500];
int tail;
dot nd(dot d){
    if(d.y==n-1){
        d.x++;
        d.y=0;
        return d;
    }d.y++;
    return d;
}
bool con(dot d){
    d.x--;
    d.y--;
    if(d.y<0)
    {
        d.x--;
        d.y=n-1;
    }
    if(d.x<0)return true;
    return map[d.x][d.y]=='0';
}
// void print(){
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<map[i][j];
//         }cout<<"\t";
//         for(int j=0;j<n;j++){
//             if(i*m+j<tail)
//             cout<<str[i*m+j];
//         }cout<<endl;
//     }cout<<endl;
// }
int used1_min=0x3f3f3f3f;
bool cmp(char a[],char b[]){
    for(int i=0;i<n;i++){
        if(a[i]<b[i])return true;
        else if(a[i]>b[i])return false;
    }
    return false;
}
void dfs(dot d,int used1){
    if(!con(d))return ;
    if(used1>used1_min)return ;
    // print();
    if(d.x==m&&d.y==0){
        int flag=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]=='1'){flag=0;break;}
            }
        }
        if(flag){
            if(result[0]){
                if(used1<used1_min){memcpy(result,str,sizeof(str));used1_min=used1;}
                else if(strcmp(str,result)<0){memcpy(result,str,sizeof(str));}
            }else {memcpy(result,str,sizeof(str));used1_min=used1;}
            // for(int i=0;i<m*n;i++){
            //     cout<<str[i];
            // }cout<<endl;
        }
        return ;
    }
    for(int i=0;i<2;i++){
        change(i,d);
        str[tail++]=i+'0';
        dfs(nd(d),used1+i);
        change(i,d);
        tail--;
    }
}
int main(){
    // freopen("D:\\mass_organizations\\ACM\\git_github\\ACMtraining\\TrainingRecord\\YYM_4.4\\4.4\\test.txt","w",stdout);

    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    dfs({0,0},0);
    if(result[0]){
    for(int i=0;i<m*n;i++){
        cout<<result[i]<<" ";
        if((i+1)%n==0)cout<<endl;
    }cout<<endl;}
    else cout<<"IMPOSSIBLE"<<endl;
    // cout<<used1_min<<endl;
    // fclose(stdout);
}