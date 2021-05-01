#include<iostream>
using namespace std;
int main(){
    int mom=0;
    int have=0;
    for(int i=0;i<12;i++){
        int spend;
        cin>>spend;
        have+=300;
        if(have<spend){
            cout<<"-"<<i+1;
            return 0;
        }
        have-=spend;
        mom+=have/100*100;
        have%=100;
    }
    cout<<(int)(mom+mom*0.2)+have;
}