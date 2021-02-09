#include<cstdio>
#include<iostream>
#include<list>
#include<string>
using namespace std;
#define ios_                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
int main(){
    // ios_
    string text_;
    while(!((cin>>text_).eof())){
        list<char> text;
        list<char>::iterator index=text.begin();
        int stop=text_.size();
        for(int i=0;i<stop;i++){
            switch (text_[i])
            {
            case '[':
                index=text.begin();
                break;
            case ']':
                index=text.end();
                break;
            default:
                text.insert(index,text_[i]);
                break;
            }
            // for(char a:text){
            //     cout<<a;
            // }cout<<endl;
        }
        index=text.begin();
        while(index!=text.end()){
            cout<<*(index++);
        }cout<<endl;

    }
    return 0;
}