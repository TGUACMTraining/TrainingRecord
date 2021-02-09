#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int repeat;
    cin>>repeat;
    while(repeat--){
        double n,i;
        double p;
        cin>>n>>p>>i;
        printf("%.4f\n",pow((1-p),i-1)*p*(1/(1-pow(1-p,n))));
    }
}