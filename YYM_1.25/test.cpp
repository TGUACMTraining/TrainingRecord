#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    string str;
    while (1)
    {
        if (getchar()!='\n')
        {
            fseek(stdin,-1,SEEK_CUR);
            cin>>str;
            cout<<str;
            getchar();
            cin>>str;
            cout<<str;
            getchar();
        }
        
    }
    
}