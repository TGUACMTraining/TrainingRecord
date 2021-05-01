#include<iostream>
using namespace std;
int main(){
    double m,h;
    cin>>m>>h;
    double b=m/h/h;
    if(b<18.5){
        cout<<"Underweight";
    }else if(b>=18.5&&b<24){
        cout<<"Normal";
    }else{
            cout<<b<<endl<<"Overweight";
    }
}