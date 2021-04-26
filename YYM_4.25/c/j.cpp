#include<iostream>
#include<cmath>
using namespace std;
double EPS=0.00000001;
bool equal(double a,double b){
    return fabs(a-b)<EPS;
}
int main(){
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(equal(y1,y2)){
        cout<<"x=";
        printf("%.4lf",(x1+x2)/2);
    }else{
        double mx,my;
        mx=x1+x2;
        my=y1+y2;
        mx/=2;
        my/=2;
        double k=y1-y2;
        k/=(x1-x2);
        k=-1/k;
        cout<<"y=";
        printf("%.4lf",k);
        cout<<"x";
        // if(equal(0,my-k*mx))return 0;
        cout<<"+";
        printf("%.4lf",my-k*mx);
        cout<<endl;
    }
}