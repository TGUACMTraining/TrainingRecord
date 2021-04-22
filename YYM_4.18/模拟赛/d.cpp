#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int x,y,z;
        cin>>x>>y>>z;
        switch (x*x+y*y+z*z==3*x*y*z)
        {
        case true:
            cout<<"Yes"<<endl;
            break;
        
        default:
            cout<<"No"<<endl;
            break;
        }
    }
}