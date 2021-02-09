#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100;
int dp[N][N];
char str[N];
int path[N][N];
void oprint(int i,int j){
    if(i>j)return ;
    if(i==j){
        if(str[i]=='['||str[i]==']')
        printf("[]");
        else
        {
            printf("()");
        }
    }else if(path[i][j]==-1){
        printf("%c",str[i]);
        oprint(i+1,j-1);
        printf("%c",str[j]);
    }else{
        oprint(i,path[i][j]);
        oprint(path[i][j]+1,j);
    }
}
int main(){
    while(cin.getline(str,N)){
    int len=strlen(str);
    if(!len){
        printf("\n");
        continue;
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<len;i++)
    dp[i][i]=1;
    for(int r=1;r<len;r++){
        for(int i=0;i+r<len;i++){
            int j=i+r;
            dp[i][j]=0x7fffffff;
            if(str[i]=='['&&str[j]==']'||str[i]=='('&&str[j]==')'){path[i][j]=-1;dp[i][j]=dp[i+1][j-1];}
            for(int k=i;k<j;k++){
                if(dp[i][k]+dp[k+1][j]<dp[i][j]){
                    path[i][j]=k;
                    dp[i][j]=dp[i][k]+dp[k+1][j];
                }
            }
        }
    }
    oprint(0,len-1);
    printf("\n");
    }
    return 0;
}