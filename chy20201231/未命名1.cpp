#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int k=1,sum,i=1,num1,num2;
		while(1)//Дэдкет 
		{
		num1=1092*k;
		sum=n-num1;
		i=sum/364;
		if(i>100||sum%364!=0||i<1)
			{
				k++;
			}
		else
			{
				break;
			}
		}
		cout<<i<<endl<<k;
	return 0;
}
