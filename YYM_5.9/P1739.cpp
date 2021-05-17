#include<iostream>
using namespace std;
int t=0;
int main(){
    char c;
    int flag=1;
    while(~scanf("%c",&c)){
        switch (c)
        {
        case '(':
            t++;
            break;
        case ')':
            t--;
            break;
        }
        if(t<0){flag=0;break;}
    }
    if(t!=0||flag==0)cout<<"NO";
    else cout<<"YES";
}