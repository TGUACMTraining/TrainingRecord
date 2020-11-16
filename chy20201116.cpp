//搜左分界点，二分尝试,找从左到右最早出现的mgoal 
/*#include<iostream>
using namespace std;
int left search(int l,int r)
{
	while(l<r)
	{
		int mid=(l+r)/2;
		if(q[mid]>=goal)//大于等于的写法是>= ，因为是左节点，所以可以等于，用于有很多个goal 时找最左边的goal 
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(q[mid]!=goal)
	{
		return -1;
	}
	return 1;
} */

/*找一个数 
int search one(int l,int r)
{
	while(l<r)
	{
		int mid=(l+r)/2;
	    if(q[mid]==goal)
	    {
	    	
		    return mid;
	    }
	    els if(q[mid]>goal)
	    {
		    r=mid;
	    }
	    else
	    {
		    l=mid+1;
	    }
	}
	return -1;
} */

//while(m--)即如果m不等于0则执行循环                  ；int 型数组 可以开到10的6次方左右

#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1000001];
int erfen(int a[],int l,int r,int k)
{
	if(r==l)
	{
		if(k==a[l])
		{
			return l;
		}
		else
		{
			return -1;
		}
	}
	if(l<r)
	 {
	 	int mid=(l+r)/2;
		if(k<=a[mid])
		{
			erfen(a,l,mid,k);
		}
		else
		{
			erfen(a,mid+1,r,k);//mid+1所以是找左节点 
		}
	 }
		
}
int main()
{
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(m--)
	{
		cin>>k;
		cout<<erfen(a,1,n,k)<<" ";
	}
	return 0;
}




 
