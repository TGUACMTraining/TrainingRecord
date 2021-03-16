#include<iostream>
using namespace std;
int main(){
    int n;
    int cache;
    int result;
    cin>>n;
    while (n--)
    {
        cin>>cache;
        cout<<"Input value: "<<cache<<endl;
        int a=0;
        int be=cache;
        while(cache=cache>>1){
            a++;
        }
        // cout<<a<<endl;
        result=1u<<a;
        if(result!=be){
            result=result<<1;
        }
        cout<<result<<"\n"<<"\n";
    }
    
}