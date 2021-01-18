#include<bits/stdc++.h>
using namespace std;
string s;
int k;
string Work(int j)
{
	int len=0;
	string ts="",as;
	while(s[j]>='0'&&s[j]<='9')
	{
		len=len*10+s[j]-'0';
		j++;
	}
	while(s[j]!=']')
	{
		if(s[j]>='A'&&s[j]<='Z') ts+=s[j];
		else if(s[j]=='[') ts+=Work(j+1),j=k;
		j++;
	}
	k=j;
	for(int l=1;l<=len;l++)
		as+=ts;
	return as;
}
int main()
{
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='[')
		{
			k=0;
			string ts=Work(i+1);
			cout<<ts;
			i=k;
		}
		else cout<<s[i];
	}
	return 0;
}
