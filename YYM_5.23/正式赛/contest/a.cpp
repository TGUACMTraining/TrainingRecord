#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    double n,x,y;
    cin>>n>>x>>y;
    double tmp=0;
    tmp=n/x;
    tmp*=(y-x);
    printf("%.4lf",tmp);
}