#include<cstdio>

using namespace std;
int arr[1000010];

int findp_ptemp;
int findp(int l,int r)
{
	int mid=(l+r)/2;
	if(l==r){
		if(arr[l]==findp_ptemp)return l;
		else return -1;
	}
	if(arr[mid]<findp_ptemp){
		return findp(mid+1,r);
	}else{
		return findp(l,mid);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",arr+i);
	}
	for(int i=1;i<=m;i++)
	{
		int tp;
		scanf("%d",&tp);
		findp_ptemp=tp;
		printf("%d ",findp(1,n));
	}
	return 0;
 } 
