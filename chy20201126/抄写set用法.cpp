#include <iostream>
#include <set>
using namespace std;
int main()
{
    std::set<int> mySet;    // 直接定义内置类型set集合
    mySet.insert(10); 
	      // 默认比较函数为less
	  
    mySet.insert(20);  
	
	     // 从小到大排序
    mySet.insert(16);    
    for(auto it:mySet)
    {
        std::cout<<it<<std::endl;
    }
    std::cout<<"end"<<std::endl;
    return 0;

}
