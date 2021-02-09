#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
    double vs,r,c,w;
    int n;
    cin>>vs>>r>>c>>n;
    while(n--){
        cin>>w;
        printf("%.3f\n",vs * r * c * w /sqrt(1+c*c*w*w));
    }
    return 0;
}