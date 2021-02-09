#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
const double pi=3.1415926;
double x(double a){
    return (1-1.73205081+pi/3)*a*a;
}
double y(double a){
    return (-1+1.73205081/2+pi/12)*a*a;
}
double z(double a){
    return (1-1.73205081/4-pi/6)*a*a;
}
int main(){
    double n;
    while(~scanf("%lf",&n)){
        printf("%.3f %.3f %.3f\n",x(n),4*y(n),4*z(n));
    }

}