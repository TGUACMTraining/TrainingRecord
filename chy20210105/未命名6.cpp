#include<iostream>
using namespace std;
int main()
{
	int a,b;
	char c;
	cin>>a>>b>>c;
	if(c=='+'||c=='-'||c=='*'||c=='/')
	{
		if(b==0&&c=='/')
		{
			cout<<"Divided by zero!";
		}
		else if(c=='+')
		{
			cout<<a+b;
		}
		else if(c=='-')
		{
			cout<<a-b;
		}
		else if(c=='*')
		{
			cout<<a*b;
		}
		else if(c=='/')
		{
			cout<<a/b;
		} 
	} 
	else
	{
		cout<<"Invalid operator!";
	}
	return 0;
}
