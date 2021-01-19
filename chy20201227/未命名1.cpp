#include<iostream>
using namespace std;
int main()
{
	int nian,yue;
	cin>>nian>>yue;
	if(yue==2)
	{
		if((nian%4==0)&&(nian%100!=0)||(nian%400==0))
		{
			cout<<29;
		}
		else
		{
			cout<<28;
		}
	}
	else
	{
		if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
		{
			cout<<31;
		}
		else
		{
			cout<<30;
		}
	}
	return 0;
} 
