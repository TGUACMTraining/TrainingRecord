
#include<iostream>
#include<cstring>



using namespace std;

int main()
{
	int a[100001] = {0};
	int n;
	cin >> n;
	while(n != 0)
	{
		int j, k;
		for(int i = 0; i < n; i ++)
		{
			
			cin >> j >> k;
			for(int ii = j;ii <= k; ii ++)
			{
				a[ii] ++;
			}
		}
		for(int ii = 1;ii <= n;ii ++)
		{
			cout << a[ii];
			if(ii!=k) cout <<" ";
		}
		cout << endl;
		memset(a,0,sizeof(a));
		cin >> n;
	}
	
 } 
