#include<iostream>
#include<string>
using namespace std;
int safe[4];
enum{big,small,num,special};
void jud(char c){
    if(c>='a'&&c<='z'){
        safe[small]=1;
        return;
    }if(c>='A'&&c<='Z'){
        safe[big]=1;
        return;
    }
    if(c>='1'&&c<='9'||c=='0'){
        safe[num]=1;
        return;
    }
    switch(c){
        case '~':
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        safe[special]=1;
    }
}
int main(){
    int m;
    cin>>m;
    while(m--){
        string mima;
        cin>>mima;
        int flag=0;
        if(mima.length()>=8&&mima.length()<=16){
        for(char c:mima){
            jud(c);
        }
        int n=safe[0]+safe[1]+safe[2]+safe[3];
        if(n>2)flag=1;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        safe[0]=safe[1]=safe[2]=safe[3]=0;
    }
}