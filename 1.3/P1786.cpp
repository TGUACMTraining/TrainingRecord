#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
string s[10]={"BangZhu","FuBangZhu","HuFa","ZhangLao","TangZhu","JingYing","BangZhong"};
struct node
{
	string Name,Pos;
	int Con,Lev;
	int dec,num,type;
}a[250];
bool cmp1(node x,node y)
{
	if(x.dec!=y.dec) return x.dec<y.dec;
	else if(x.Con!=y.Con) return x.Con>y.Con;
	else return x.num<y.num;
}
void Cla(int l,int r,int t)
{
	if(l>n) return;
	if(r>n) r=n;
	for(int i=l;i<=r;i++)
		a[i].type=t;
}
bool cmp2(node x,node y)
{
	if(x.type!=y.type) return x.type<y.type;
	else if(x.Lev!=y.Lev) return x.Lev>y.Lev;
	else return x.num<y.num;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].Name>>a[i].Pos>>a[i].Con>>a[i].Lev;
		if(a[i].Pos=="BangZhu") a[i].dec=0;
		else if(a[i].Pos=="FuBangZhu") a[i].dec=cnt++;
		else a[i].dec=3;
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp1);
	Cla(1,1,0);
	Cla(2,3,1);
	Cla(4,5,2);
	Cla(6,9,3);
	Cla(10,16,4);
	Cla(17,41,5);
	Cla(42,n,6);
	sort(a+4,a+1+n,cmp2);
	for(int i=1;i<=n;i++)
		cout<<a[i].Name<<" "<<s[a[i].type]<<" "<<a[i].Lev<<endl;
	return 0;
}
