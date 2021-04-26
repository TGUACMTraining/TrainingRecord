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
int main(){
    string s;
    cin>>s;
    if(s.length()==4){
        int year=(s[0]-'0')*10+s[1]-'0';
        if(year<22)cout<<20;
        else cout<<19;
        cout<<s[0]<<s[1];
        cout<<"-";
        cout<<s[2]<<s[3]<<endl;
    }
    else{
        cout<<s[0]<<s[1]<<s[2]<<s[3]<<"-"<<s[4]<<s[5]<<endl;
    }
}
