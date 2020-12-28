#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool cmp(int a, int b)
{
    return a > b; //排序依据,默认a<b,升序
}
int main()
{
    int a[] = {2, 5, 1, 5, 1, 6, 2, 4, 8, 0, 5, 56, 2};
    vector<int> arr = {2, 5, 1, 5, 1, 6, 2, 4, 8, 0, 5, 56, 2};
    sort(a, a + 13);
    sort(a, a + 13, cmp);
    nth_element(arr.begin(), arr.begin() + 5, arr.end());
    swap(a[3], a[9]);
    reverse(arr.begin(), arr.end());                              //反转arr
    int newlength = unique(arr.begin(), arr.end()) - arr.begin(); //有效部分内元素是不重复的
    {
        //代替手写二分查找
        sort(arr.begin(), arr.end());
        bool exist = binary_search(arr.begin(), arr.end(), 1);
        int first_location = lower_bound(arr.begin(), arr.end(), 5) - arr.begin();
        int last_location = upper_bound(arr.begin(), arr.end(), 5) - arr.begin();
    }
}