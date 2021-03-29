#include<iostream>
#include<cmath>
using namespace std;
int main(){
int N;
double R;
while (cin>>N>>R)
{
    double result=0;
    while (N--)
    {
        double  cache;
        cin>>cache;
        result+= sin(cache/360*2*asin(1)*2 );
    }
    result/=2;
    result*=R*R;
    printf("%.3f\n",result);
}

}