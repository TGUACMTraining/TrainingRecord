#include<iostream>
using namespace std;
int limit=10000;
int main(){
    long long cnt=0;
    for(int x=0;x<limit;x++){
        for(int y=0;y<limit;y++){
            if(x*x+y*y<2*x*limit)
            for(int z=0;z<limit;z++){
                if(x*x+y*y+z*z<4*limit*limit){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt*4<<endl;
    cout<<(long long)(10*(3.14/2-2.0/3)*limit*limit*limit)<<endl;
    cout<<(long long)(32.0/3*(3.14/2-2.0/3)*limit*limit*limit)<<endl;
    cout<<(long long)(10*(3.14/2-4.0/3)*limit*limit*limit)<<endl;
    cout<<(long long)(32.0/3*(3.14/2-4.0/3)*limit*limit*limit)<<endl;
}