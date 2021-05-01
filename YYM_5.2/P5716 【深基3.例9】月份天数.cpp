#include<iostream>
using namespace std;
bool j(int year){
    if(year%400==0)return true;
    if(year%100==0)return false;
    if(year%4==0)return true;
    return false;
}
int arr[]={30,31,0,31,30,31,30,31,31,30,31,30,31};
int main(){
    int year;
    int month;
    cin>>year>>month;
    if(month==2){
        if(j(year))
        {
            cout<<"29";
        }else cout<<"28";
    }else{
        cout<<arr[month];
    }
}