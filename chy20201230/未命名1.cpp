#include<iostream>
using namespace std;
int main()
{
	int L,c[100000];
	cin>>L;
	int i=3,sum,j,b,a;
	bool k=1;
	int d=1;
	while(sum<=L)
	{
		b=i/2;
		for(j=i-1;j>=b;j--)
		{
			for(a=2;a<=b;a++)
			{
				if(a*j==i)
				{
					k=0;
				}
			}
			if(k=0)
			{
				break;
			}
		}
		if(k=1)
		{
			c[d]=i;
			d++;
			sum+=i;
		}
		i+=2;
	}
	cout<<2<<endl;
	for(int i=1;i<d;i++)
	{
		cout<<c[i]<<endl;
	}
	cout<<d+1;
	return 0;
} 
