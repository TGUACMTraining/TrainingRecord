#include<bits/stdc++.h>
using namespace std;
const int N=5000100;
int n,k;
int a[N],b[N];
int qsort(int l,int r)
{
	int m=a[l],i=l,j=r;
	while(i<j)
	{
		while(a[j]>=m&&i<j) j--;
		a[i]=a[j];
		while(a[i]<=m&&i<j) i++;
		a[j]=a[i];
	}
	a[i]=m;
	if(k==i) return a[i];
	else if(k>j) return qsort(j+1,r);
	else if(k<i) return qsort(l,i-1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d",qsort(0,n-1));
	return 0;
}
