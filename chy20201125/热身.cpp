//C++标准库中stringstringstring类以类型的形式对字符串进行封装，且包含了字符序列的处理操作。

#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			s[i]-=32;
		}
	}
	cout<<s;
	return 0;
}
