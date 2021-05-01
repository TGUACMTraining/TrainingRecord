#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int flag=0;
    if(s[0]=='-'){
    cout<<"-";
    s.erase(s.begin());
    }
    reverse(s.begin(),s.end());
    for(char c:s){
        if(c!='0')flag=1;
        if(flag)cout<<c;
    }
    if(flag==0)cout<<0;
}