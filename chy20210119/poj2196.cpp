#include<iostream>
using namespace std;
int main()
{
	int i;
	for(i=2992;i<=9999;i++)
	{
		int a[3]={0},b[3];
		b[0]=i;
		b[1]=i;
		b[2]=i;
		while(b[0])
		{
			a[0]+=b[0]%10;
			b[0]/=10;
		}
		while(b[1])
		{
			a[1]+=b[1]%12;
			b[1]/=12;
		}
		while(b[2])
		{
			a[2]+=b[2]%16;
			b[2]/=16;
		}
		if(a[0]==a[1]&&a[1]==a[2])
		{
			cout<<i<<endl;
		}
	}
	return 0;
} 
