//http://acm.hdu.edu.cn/showproblem.php?pid=1027

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getFactorial(int num) {
    if (num == 0) {
        return 1;
    }
    if (num == 1)
        return 1;
    if (num > 1) {
        return num * getFactorial(num - 1);
    }
}

void show(vector<int> num) {
    for (int i = 0; i < num.size() - 1; i++) {
        cout << num[i] << ' ';
    }
    cout << num[num.size() - 1];
}

vector<int> getNum(int num) {
    vector<int> ans;
    for (int i = 1; i <= num; i++) {
        ans.push_back(i);
    }
    return ans;
}

void insertNumOrder(vector<int>& num, int lhs, int rhs) {
    num.insert(num.begin() + lhs, num[rhs]);
    num.erase(num.begin() + rhs + 1);
}

void change(vector<int>& num, int target) {
    int level = 1;
    while (target > getFactorial(level))
        level++;

    while (target > 1) {
        int pos = 0;
        int standard = getFactorial(--level);
        int targetBuf = target;
        while (targetBuf > standard) {
            standard += getFactorial(level);
            target -= getFactorial(level);
            pos++;
        }
        insertNumOrder(num, num.size() - level - 1, num.size() - level - 1 + pos);
    }
}

int main() {
    int num;
    int order;
    vector<int> ans;
    // while (cin >> num >> order) {
    //     ans = getNum(num);
    //     change(ans, order);
    //     show(ans);
    // }
    int thenum;
    cin >> thenum;
    for (int i = 1; i <= getFactorial(thenum) - 1; i++) {
        vector<int> ans = getNum(thenum);
        change(ans, i);
        // cout << i << endl;
        show(ans);
        cout << '\n';
    }
    ans = getNum(thenum);
    change(ans, getFactorial(thenum));
    // cout << i << endl;
    show(ans);
    return 0;
}
