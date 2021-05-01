#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string s1,s2,s3;
    cin>>s1;
    getchar();
    getline(cin,s2);
    int limit=s1.length();
    for(int i=0;i<limit;i++){
        s1[i]=tolower(s1[i]);
    }
    limit=s2.length();
    for(int i=0;i<limit;i++){
        s2[i]=tolower(s2[i]);
    }
    s1=' '+s1+' ';
    s2=' '+s2+' ';
    int pos;
    int fp=-1;
    int cnt=0;
    while(((pos=s2.find(s1))!=-1)){
        // cout<<pos<<endl;
        // cout<<s2<<endl;
        cnt++;
        if(fp==-1){fp=pos;}
        s2=s2.substr(pos+s1.length()-1);
        // cout<<s2<<endl;
    }
    if(cnt)cout<<cnt<<" ";
    cout<<fp;
}