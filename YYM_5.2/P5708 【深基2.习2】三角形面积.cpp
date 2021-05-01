#include<cmath>
#include<iostream>
using namespace std;
int main(){
    double a,b,c;
    cin>>a>>b>>c;
    double p;
    p=a+b+c;
    p/=2;
    printf("%.1lf",sqrt(p*(p-a)*(p-b)*(p-c)));
}