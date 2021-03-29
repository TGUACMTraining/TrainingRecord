#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string ,int>numbers={{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},{"zero",0}};
int main(){
    int a,b;
    while(true){
        a=b=0;
        string cache;
        while (cin>>cache)
        {
            if(cache=="+")break;
            else {a*=10;a+=numbers[cache];}
        }
        while (cin>>cache)
        {
            if(cache=="=")break;
            else {b*=10;b+=numbers[cache];}
        }
        if(a||b){
            cout<<a+b<<endl;
        }else{break;}
    }
    return 0;
}