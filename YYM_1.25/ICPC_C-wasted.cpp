#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main(){
    string key;
    string value;
    map<string ,string >dictionary;
    char cache;
    while (cache=getchar(),cache!='\n')
    {
        cin>>value>>key;
        value=cache+value;
        // cout<<key<<" "<<endl;
        dictionary[key]=value;
        getchar();
    }
    string translate;
    while (!(cin>>translate).eof())
    {
        if(dictionary[translate]!="")
        {
            cout<<dictionary[translate]<<endl;
        }else{
            cout<<"eh"<<endl;
        }
    }
    
    return 0;
}