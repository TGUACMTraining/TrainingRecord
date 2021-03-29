#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    string a,b;
    while(cin>>a>>b){
        int flag=1;
        for(int i=0;i<a.length();i++){
            if(a[i]=='.'){flag=0;break;}
        }
        if(flag)a.push_back('.');
        flag=1;
        for(int i=0;i<b.length();i++){
            if(b[i]=='.'){flag=0;break;}
        }
        if(flag)b.push_back('.');
        string::iterator index=a.end()-1;
        while (*index=='0'||*index=='.')
        {
            a.erase(index);
            if(*index=='.')break;
            index--;
        }
        index=a.begin();
        while (*index=='0')
        {
            a.erase(index);
        }
        
        index=b.end()-1;
        while (*index=='0'||*index=='.')
        {
            b.erase(index);
            if(*index=='.')break;
            index--;
        }
        index=b.begin();
        while (*index=='0')
        {
            b.erase(index);
        }
        if(a==b){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
