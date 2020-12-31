#include <iostream>
using namespace std;
#define Max_Num (unsigned long long)1e9
 
char isPrime[Max_Num+10]; //1为和数   0为质数 
int main(){
	for(unsigned long long i=1;i<=Max_Num+10;i++)
		isPrime[i]=0; 
	unsigned long long k=0;	
	for(unsigned long long i=2;i<=Max_Num;i++)
		if(isPrime[i]==0)
		{k=i; 
			for(unsigned long long j=i*2;j<=Max_Num;j+=i)
				isPrime[j]=1;//1的就是 和数 
}
					
	//for(unsigned long long i=2;i<=Max_Num;i++)
		
	//for(unsigned long long i=2;i<=Max_Num;i++)
		//if(isPrime[i]==1)cout << i<<" ";
	
	//for(unsigned long long i=Max_Num;true;i--)
		//if(isPrime[i]==0)
		
	//	{	cout<<i;
	//		break;	} 
	cout << k;
	
	
}
