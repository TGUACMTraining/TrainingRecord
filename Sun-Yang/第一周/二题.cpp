#include<iostream>
#include<algorithm>

#include<stdio.h>
using namespace std;
int main()
{
	int n;
	int count = 0;
	cin >> n;
	int a[1000] = {0} ;
	for(int i = 0;i < n;i ++)
	{
			int m;
			scanf("%d",&m);
			 
		if(a[m] == 0)
		{
			a[m] = 1;
			count ++;
		}
	}
	
	cout << count << '\n';
		
		
	for(int i = 0;i < 1000;i ++)
	{
		if(a[i] == 1)
		{
			printf("%d",i);
			
			
			
			
			printf(" "); 
		 	
			
		}
	}
}
