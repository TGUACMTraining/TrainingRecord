#include<iostream>
using namespace std;
int feibonaqi(long long n)
{
	if(n==1)
	{
		return 1;
	}
	else if(n==0)
	{
		return 1;
	}
	else
	{
		return feibonaqi(n-1)+feibonaqi(n-2);
	}
}
int main()
{
	long long n;
	cin>>n;
	feibonaqi(n);
	cout<<feibonaqi(n)<<endl;
	return 0;
}
