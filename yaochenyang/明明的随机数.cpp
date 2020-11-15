#include<iostream>
using namespace std; 
int main()
{
	int N,l=0;
	int n[100]={0};
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>n[i]; 
	} 
	for(int j=0;j<N-1;j++)
	{
		for(int k=j+1;k<N;k++)
		{
			if(n[j]>n[k])
			{
				int t=n[k];
				n[k]=n[j];
				n[j]=t;
			}
			if(n[j]==n[k])
			{
				n[k]=0;
				l++;
			}
		}
		
	}
	cout<<N-l<<endl;
	for(int i=0;i<N;i++)
	{
		if(n[i]!=0)
		cout<<n[i]<<" ";
	}
} 
