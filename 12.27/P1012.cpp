#include<bits/stdc++.h>
using namespace std;
int n;
bool v[23];
string s[23];
int J(int x,int y)
{//cout<<x<<" "<<y<<endl;
	int flag=0;
	int l=min(s[x].length(),s[y].length());
	for(int i=0;i<l;i++)
		if(s[x][i]!=s[y][i])
			flag=1;
	if(flag) return s[x]<s[y]?y:x;
	else if(s[x].length()>s[y].length()) return s[x][l]>s[x][0]?x:y;
	else return s[y][l]>s[y][0]?y:x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=1;j<=n;j++)
			if(!v[j])
			{//cout<<k<<" "<<j<<endl;
				if(!k) k=j;
				else k=J(k,j);
			}
		cout<<s[k];
		v[k]=1;
	}
	return 0;
}
