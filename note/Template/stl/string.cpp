#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str = "hello";
    str.push_back('!');
    cout << str << endl;
    getline(cin, str); //输入一整行
    cout << str << endl;
    str.length(); //O(n)
    str.size();   //O(n)
    {
        str.insert(1, "aaa");         //O(n)
        str.insert(str.begin(), 'a'); //O(n)
    }
    str.c_str(); //返回一个指针char* 将string转化为char ?[]
    {
        string str_ = "aaaaa";
        str.compare(str_);
    }
    str += "a";
    str += 'a';
}