#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int three;
    int two;
    int q;
    q=n/2;
    three=n%2;
    n-=three*3;
    two=n/2;
    cout<<q<<endl;
    for(int i=0;i<two;i++){
        cout<<"2 ";
    }
    if(three){
        cout<<"3"<<endl;
    }
}