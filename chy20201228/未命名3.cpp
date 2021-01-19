#include<iostream>
using namespace std;
int main()
{
	int n,i,ans=1,a;
	cin>>n;
	for(i=n;i>=1;i--)
	{
		for(a=1;a<=i;a++)
		{
			if(ans<10)
			{
				cout<<0<<ans;
				ans++;
			}
			else
			{
				cout<<ans;
				ans++;
			}
		}
		cout<<endl;
	}
	return 0;
}
