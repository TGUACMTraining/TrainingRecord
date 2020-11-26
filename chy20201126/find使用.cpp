#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
int main()
{
	int n1=3,n2=5;
	std::vector<int>v{0,1,2,3,4};
	auto result1=std::find(std::begin(v),std::end(v),n1);
	if(result1!=std::end(v))
	{
		std::cout<<1<<" "<<n1;
	}
	else
	{
		std::cout<<2<<n1;
	}
	return 0;
}
