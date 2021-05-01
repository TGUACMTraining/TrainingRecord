#include<iostream>  
#include<cmath>
using namespace std;
double pi=3.141593;

int main(){
    int n;
    cin>>n;
    switch (n)
    {
    case 1:
        cout<<"I love Luogu!"<<endl;
        break;
    case 2:
        int a,u,b;
        a=2,u=4,b=10-a-u;
        cout<<a+u<<" "<<b<<endl;
        break;
    case 3:
        cout<<14/4<<endl;
        cout<<14/4*4<<endl;
        cout<<14-14/4*4<<endl;
        break;
    case 4:
        printf("166.667\n");
        break;
    case 5:
        cout<<(260+220)/(12+20)<<endl;
        break;
    case 6:
        cout<<sqrt(6*6+9*9)<<endl;
        break;
    case 7:
        cout<<"110\n90\n0"<<endl;
        break;
    case 8:
        cout<<pi*5*2<<endl<<pi*5*5<<endl<<4.0/3*pi*5*5*5<<endl;
        break;
    case 9:
        cout<<"22"<<endl;
        break;
    case 10:
        cout<<24-15<<endl;
        break;
    case 11:
        cout<<100.0/3<<endl;
        break;
    case 12:
        cout<<'M'-'A'+1<<endl<<(char)('A'+18-1)<<endl;
        break;
    case 13:
        {double v1,v2;
        v1=4;
        v2=10;
        v1*=4.0/3*v1*v1*pi;
        v2*=4.0/3*v2*v2*pi;
        double res=v1+v2;
        cout<<(int)pow(res,1.0/3);}
        break;
    case 14:
        cout<<110-60<<endl;
        break;
    }
}