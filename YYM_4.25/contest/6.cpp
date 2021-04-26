#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<ctime>
using namespace std;
vector<string> problems;
int solve[100];
int tail=0;
int main(){
    int n;
    int m;
    cin>>n>>m;
    int flag=1;
    int flag2=1;
    getchar();
    for(int i=0;i<n;i++){
        string problem;
        getline(cin,problem);
        problems.push_back(problem);
    }
    int index=0;
    for(;index<n;index++){
        // cout<<problems[index]<<endl;
        int x=problems[index].find("qiandao");
        int y=problems[index].find("easy");
        if(x==-1)
        if(y==-1)
        solve[tail++]=index;
    }
    if(m>=tail){
        cout<<"Wo AK le"<<endl;
    }else{
        cout<<problems[solve[m]]<<endl;
    }
}