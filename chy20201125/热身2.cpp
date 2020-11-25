#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		int x=n%26;
		if(n==26)
		{
			continue;
		}
		else
		{
			s[i]+=x;
		}
	}
	cout<<s;
	return 0;
}
