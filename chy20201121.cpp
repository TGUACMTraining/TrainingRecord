#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int x[110]; 
void qsort (int l,int r);
int main (void)
{
	int n,i;
	cin>>n;
	for (i=1;i<=n;i++) {
		cin>>x[i];
	}
	qsort(1,n);
	for (i=1;i<=n;i++) {
		cout<<x[i]<<' ';
	}
	return 0;
}

void qsort (int l,int r)
{
	int i=l,j=r,mid,p;
	mid=x[(l+r)/2];
	do {
		while (x[i]<mid) i++;
		while (x[j]>mid) j--;
		if (i<=j) {
			p=x[i];
			x[i]=x[j];
			x[j]=p;
			i++;
			j--;
		}
	}while (i<=j);
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}
