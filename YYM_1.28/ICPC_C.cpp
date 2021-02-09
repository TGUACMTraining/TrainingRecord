#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
struct words
{
    int end;
    string *str;
}dict[2];
void build(){
    for(int i=0;i<2;i++){
        delete(dict[i].str);
        dict[i].end=1;
        dict[i].str=new string[1000];
    }
}
void inj(int which_one,string what){
    int len=what.length();
    for(int i=0;i<len;i++){
        if(isalpha(what[i]))
        dict[which_one].str[dict[which_one].end]+=what[i];
        else 
        if(dict[which_one].str[dict[which_one].end].length())
        dict[which_one].end++;
    }
    if(dict[which_one].str[dict[which_one].end].length())dict[which_one].end++;
}
int ans[1000][1000];
int main(){
    dict[0].str=0;
    dict[1].str=0;
    string cache1;
    string cache2;
    int out=0;
    while (getline(cin,cache1))
    {
        getline(cin,cache2);
        printf("%2d. ",++out);
        if(cache2.length()==0){printf("Blank!\n");continue;}
        build();
        inj(0,cache1);
        inj(1,cache2);
        memset(ans,0,sizeof(ans));
        for(int i=1;i<dict[0].end;i++){
            for(int j=1;j<dict[1].end;j++){
                ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
                if(dict[0].str[i]==dict[1].str[j]){ans[i][j]=max(ans[i][j],ans[i-1][j-1])+1;}
            }
        }
        printf("Length of longest match: %d\n",ans[dict[0].end-1][dict[1].end-1]);
    }
    
}