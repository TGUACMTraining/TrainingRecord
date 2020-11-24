#include<vector>
#include<iostream>
int main()
{
	std::vector<int> v={7,5,16,8};//创建含有整数的vector 
	v.push_back(25);
	v.push_back(16);//非集合是数组 
	for(int n:v)
	{
		std::cout<<n<<'\n';//遍历v数组 
		
	} 
	
}
