#include<iostream>
#include<algorithm>

using namespace std;

int a[1000000];int b[1000];int main(){
	int n,k;
		cin >> n>>k;
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}
	for(int i=0;b[i]!=0;i++){
		
		for(int j=i+1;j<n;j++)
		{
			int k=b[i]+b[j];
			a[k] = 1;
		}
	}
	
	for(int i =0;i<1000000;i++)
	{
		if(a[i]==1) cout<<i;
	}
	

	
}
