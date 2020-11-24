#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int a[1000001];
int erfen(int a[],int r,int r1,int k)
{
	if(r==r1)
	
	
	{
		if(k==a[r]) return r;
		else return -1;
	}
	int mid = (r+r1)/2;
	if(k<=a[mid])
	{
		erfen(a,r,mid,k);
	}
	else
	{
		erfen(a,mid+1,r1,k);
	}
	
}


int main()
{
	int n;
	int m,k;
	
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n;i ++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<=m;i++)
	{
		cin >> k;
		cout << erfen(a,1,n-1,k) << " "; 
	}
 } 
