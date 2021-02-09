#include<iostream>
#include<list>
#include<sstream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1000][1000];
int main(){
    int n=0;
    string cache[2];
    while(getline(cin,cache[0])){
        getline(cin,cache[1]);
        printf("%2d. ",++n);
        if(!cache[0].size()||!cache[1].size()){
            printf("Blank!\n");
            continue;
        }
        stringstream ss[2];
        list<string>words[2];
        for(int i=0;i<2;i++){
            for(int j=0;j<cache[i].size();j++){
                if(isalpha((cache[i])[j])||isdigit((cache[i])[j]));
                else (cache[i])[j]=' ';
            }
            ss[i]<<cache[i];
            while(ss[i]>>cache[i]){
                if(cache[i]!="")
                words[i].push_back(cache[i]);
                cache[i]="";
            }
        }
        memset(dp,0,sizeof(dp));
        int i,j;
        i=j=1;
        int ans=0;
        for(string str1:words[0]){
            j=0;
            for(string str2:words[1]){
                if(str1==str2){
                    dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                ans=max(ans,dp[i][j]);
                j++;
            }i++;
        }
        cout<<"Length of longest match: "<<ans<<endl;

    }
}