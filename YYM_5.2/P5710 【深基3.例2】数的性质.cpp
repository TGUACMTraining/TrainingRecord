#include<iostream>
using namespace std;
int main(){
    int n;
    int i=0,j=0;
    cin>>n;
    if(n%2==0)i=1;
    if(n>4&&n<=12)j=1;
    printf("%d %d %d %d",i&&j,i||j,i^j,!i&&!j);
}
