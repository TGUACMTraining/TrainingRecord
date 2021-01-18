#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
int t,n;
struct node
{
	int w,h;
	int ans,num;
}a[N];
bool cmp1(node x,node y)
{
	if(x.h!=y.h) return x.h<y.h;
	else return x.w<y.w;
}
bool cmp2(node x,node y)
{
	return x.num<y.num;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].h>>a[i].w;
			if(a[i].h>a[i].w) swap(a[i].h,a[i].w);
			a[i].num=i;
		}
		sort(a+1,a+1+n,cmp1);
		int min1=1e9+1,min2=1e9+1,pos1=-1,pos2=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].h!=a[i-1].h)
			{
				if(min1>min2)
				{
					min1=min2;
					pos1=pos2;
				}
			}
			if(a[i].w>min1) a[i].ans=pos1;
			else
			{
				a[i].ans=-1;
				if(a[i].w<min2)
				{
					pos2=a[i].num;
					min2=a[i].w;
				}
			}
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++)
			cout<<a[i].ans<<" ";
		cout<<endl;
	}
	return 0;
}
