#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int bp[3]={a,b,c};
	sort(bp,bp+3);
	char A;
	for(int i=1;i<=3;i++)
	{
		cin>>A;
		if(A=='A')
		{
			cout<<bp[0]<<" ";
		}
		else if(A=='B')
		{
			cout<<bp[1]<<" ";
		}
		else if(A=='C')
		{
			cout<<bp[2]<<" ";
		}
	}
	return 0;
}
