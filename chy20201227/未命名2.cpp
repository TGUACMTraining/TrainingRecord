#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int dp[3]={a,b,c};
	sort(dp,dp+3);
	if(dp[0]+dp[1]<=dp[2])
	{
		cout<<"Not triangle"; 
	} 
	else
	{
		if(dp[0]*dp[0]+dp[1]*dp[1]==dp[2]*dp[2])
		{
			cout<<"Right triangle"<<endl;
		}
		else if(dp[0]*dp[0]+dp[1]*dp[1]>dp[2]*dp[2])
		{
			cout<<"Acute triangle"<<endl;
			if(dp[0]==dp[1])
			{
				if(dp[1]==dp[2])
			{
				cout<<"Isosceles triangle"<<endl<<"Equilateral triangle";
			}
			else
			{
				cout<<"Isosceles triangle";
			}
			}
		}
		else if(dp[0]*dp[0]+dp[1]*dp[1]<dp[2]*dp[2])
		{
			cout<<"Obtuse triangle"<<endl;
			if(dp[0]==dp[1])
			{
				cout<<"Isosceles triangle";
			}
		}
	} 
	return 0;
}
