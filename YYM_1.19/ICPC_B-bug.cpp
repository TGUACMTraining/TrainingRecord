#include<string>
#include<iostream>
#include<list>
#include<ctype.h>
using namespace std;
int main(){
    string str;

    while(getline(cin,str))
    {
        list<char> result;
        for(int i=0;i<str.length();i++){
            result.push_back(str[i]);
        }
        result.push_back(' ');
        int power=1;
        char app=0;
        for(list<char>::iterator c=result.begin();c!=result.end();c++){
            if(power==1&&(isalpha(*c))){
                power=0;
                switch(*c){
                    default:app=*c;
                    c=result.erase(c);
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
                    break;
                }
            }
            if(power==0&&(!isalpha(*c))){
                power=1;
                if(app) result.insert(c,app);
                result.insert(c,'a');
                result.insert(c,'y');
                app=0;
                while(*c!=' ')c++;
            }
        }
        result.pop_back();
        result.push_back('\n');
        for(char c:result){
            cout<<c;
        }
    }



    return 0;
}
//this is a very long text