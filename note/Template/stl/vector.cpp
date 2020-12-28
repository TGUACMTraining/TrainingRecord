#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> arr(100);
    vector<int> list;
    vector<int>::iterator p;
    p = arr.begin();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    for (int i = 0; i < 10; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    for (p = arr.begin(); p != arr.end() /*空位置*/; p++)
    {
        cout << *p << endl;
    }
    return 0;
}
    // list.size();       //数组元素个数
    // list.clear();      //清空数组
    // list.empty();      //判断数组是否为空
    // list.begin();      //数组的首元素迭代器
    // list.end();        //数组最后一个元素的迭代器
    // list.erase(p);     //删除在p位置的元素O(n)
    // list.push_back(x); //添加一个元素x
    // list.pop_back();   //删除最后一个元素
