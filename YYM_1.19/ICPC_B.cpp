#include<string>
#include<iostream>
#include<list>
#include<ctype.h>
using namespace std;
int main(){
        char c;
        int power=1;
        char app=0;
        while(~scanf("%c",&c)){
            if(power==1&&(isalpha(c))){
                power=0;
                switch(c){
                    default:app=c;
                    break;
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    cout<<c;
                }
            }
            else if(power==0&&(!isalpha(c))){
                power=1;
                if(app) cout<<app;
                cout<<"ay"<<c;
                app=0;
            }else{
                cout<<c;
            }
        }
    return 0;
}
//this is a very long text