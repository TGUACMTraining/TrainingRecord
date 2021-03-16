#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int check(int num){
    stringstream result;
    result<<num;
    string cache;
    result>>cache;
    int len=cache.length();
    int flag=1;
    int index_l=0;
    int index_r;
    while (index_l<(index_r=len-index_l-1))
    {
        if(cache[index_l]!=cache[index_r]){
            flag=0;
            break;
        }
        index_l++;
    }
    return flag;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int cost;
        int tip;
        cin>>cost;
        cout<<"Input cost: "<<cost<<endl;
        tip=cost/5;
        if(tip*5!=cost){
            tip++;
        }
        while(!check(tip+cost))tip++;
        cout<<tip<<" "<<tip+cost<<endl<<endl;
    }
}