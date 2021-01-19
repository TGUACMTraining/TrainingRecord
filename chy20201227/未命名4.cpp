#include<iostream>
using namespace std;
int main()
{
	int a,b=0;
	cin>>a;
	while(a>=1)
	{
		a/=2;
		b++;
	}
	cout<<b;
	return 0;
}
