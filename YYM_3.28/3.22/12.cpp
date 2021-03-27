#include<iostream>
using namespace std;
int main(){
    string cache;
    double sum=0;
    double a,b;
    while(cin>>cache){
        cin>>a>>b;
        sum+=a*b;
    }
        printf("%.1f\n",sum);
}