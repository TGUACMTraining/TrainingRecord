#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
map<int,string>mq;
int t,ans;
string s[9];
int ansa[100];
int main()
{
	mq[0]="####.##.##.####";
	mq[1]="..#..#..#..#..#";
	mq[2]="###..#####..###";
	mq[3]="###..####..####";
	mq[4]="#.##.####..#..#";
	mq[5]="####..###..####";
	mq[6]="####..####.####";
	mq[7]="####.##.#..#..#";
	mq[8]="####.#####.####";
	mq[9]="####.####..####";
	mq[10]="....#.###.#....";
	mp[mq[0]]=0;
	mp[mq[1]]=1;
	mp[mq[2]]=2;
	mp[mq[3]]=3;
	mp[mq[4]]=4;
	mp[mq[5]]=5;
	mp[mq[6]]=6;
	mp[mq[7]]=7;
	mp[mq[8]]=8;
	mp[mq[9]]=9;
	mp[mq[10]]=10;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<5;i++)
			cin>>s[i];
		int l=s[0].length();
		int temp=0; ans=0;
		memset(ansa,0,sizeof(ansa));
		for(int i=0;i<(l+1)/4;i++)
		{
			string a="";
			for(int j=0;j<5;j++)
				a=a+s[j][i*4+0]+s[j][i*4+1]+s[j][i*4+2];
			if(mp[a]==10)
			{
				ans+=temp;
				temp=0;
			}
			else temp=temp*10+mp[a];
		}
		ans+=temp;
		while(ans)
		{
			ansa[++ansa[0]]=ans%10;
			ans/=10;
		}
		for(int i=0;i<5;i++)
			for(int j=ansa[0];j>=1;j--)
			{
				if(j!=1) cout<<mq[ansa[j]][i*3]<<mq[ansa[j]][i*3+1]<<mq[ansa[j]][i*3+2]<<".";
				else cout<<mq[ansa[j]][i*3]<<mq[ansa[j]][i*3+1]<<mq[ansa[j]][i*3+2]<<endl;
			}
		cout<<endl;
	}
	return 0;
}
