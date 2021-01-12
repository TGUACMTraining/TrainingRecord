#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
unsigned long long n;
int main()
{
	scanf("%lld",&n);
	printf("%lld",n/2*(n-1)/3*(n-2)/4*(n-3));
	return 0;
}
