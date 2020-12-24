#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=3.141593;
int main()
{
	int t;
	cin>>t;
	if(t==1)
	{
		cout<<"I love Luogu!";
	}
	else if(t==2)
	{
		cout<<6<<" "<<4;
	}
	else if(t==3)
	{
		cout<<3<<endl;
		cout<<12<<endl;
		cout<<2;
	}
	else if(t==4)
	{
		double a=500,p;
		p=a/3;
		printf("%.3lf",p);
	}
	else if(t==5)
	{
		cout<<15;
	}
	else if(t==6)
	{
		double n=sqrt(117);
		cout<<n;
	}
	else if(t==7)
	{
		cout<<110<<endl;
		cout<<90<<endl;
		cout<<0;
	}
	else if(t==8)
	{
		double zhouchang,mianji,tiji;
		zhouchang=10*3.141593;
		mianji=25*3.141593;
		tiji=4/3*3.141593*125;
		cout<<zhouchang<<endl;
		cout<<mianji<<endl;
		cout<<tiji<<endl;
	}
	else if(t==9)
	{
		cout<<22;
	}
	else if(t==10)
	{
		cout<<9;
	}
	else if(t==11)
	{
		cout<<1.0*100/3;//直接输出默认是整形 
	}
	else if(t==12)
	{
		cout<<13<<endl;
		cout<<"R"<<endl;
	}
	else if(t==13)
	{
		cout<<(int)(pow(4/3*pi*(4*4*4+10*10*10),1.0*1/3));
		cout<<(int)(pow(4/3*3.141593*(4*4*4+10*10*10),1.0*1/3));
	}
	else if(t==14)
	{
		cout<<50;
	}
	return 0;
}
