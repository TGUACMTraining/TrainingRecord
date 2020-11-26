#include<iostream>
#include<set>//除重 排序 
using namespace std;
int main()
{
	std::set<int> mySet;
	mySet.insert(5);
	mySet.insert(16);
	mySet.insert(59);//从小到大比较，默认比较函数是less 

	for(auto it:mySet)
	{
		std::cout<<it<<std::endl;
	}
	std::cout<<"end"<<std::endl;
	return 0;
}
//后面的set暂时看不懂，具体说法是插入新元素时两次让set返回false即与原数相等，不插入set中 
// https://www.cnblogs.com/litaozijin/p/6665595.html
