//错误的高精度乘法 
#include<iostream>
#include<cstring>
using namespace std;
int a[10000],b[10000],c[10000];
int main()
{
	int i,j;
	string s1,s2;
	cin>>s1>>s2;
	int lena=s1.length();
	int lenb=s2.length();
	int a1,a2;
	for(a1=1;a1<=lena;a1++)
	{
		a[a1]=s1[lena-a1]-'0';
	}
	for(a2=1;a2<=lenb;a2++)
	{
		b[a2]=s2[lenb-a2]-'0';
	}
	for(i=1;i<=lena;i++)
	{
		for(j=1;j<lenb;j++)
		{
			c[i+j-1]+=a[i]*b[j];
		}
	}
	int lenc=lena+lenb-1;
	int l;
	for(l=1;l<=lenc;l++)
	{
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
	}
	lenc++;
	while(lenc>1&&c[lenc]==0)
	{
		lenc--;
	}
	for(int h=lenc;h>=1;h--)
	{
		cout<<c[h];
	}
	return 0;
	
} 
