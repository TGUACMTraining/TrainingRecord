https://www.luogu.com.cn/problem/P1059#submit

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int num;
    cin >> num;
    vector<int> nums;
    for (int i = 0; i < num; i++) {
        int value;
        cin >> value;
        nums.push_back(value);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0, j = 1; j < nums.size(); ) {
        if (nums[i] == nums[j]) {
            nums.erase(nums.begin() + j);
        }else{
            i++;
            j++;
        }
    }

    cout << nums.size() << '\n';
    for(int i:nums){
        cout << i << ' ';
    }

    return 0;
}
