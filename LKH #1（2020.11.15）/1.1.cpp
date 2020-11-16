http://acm.hdu.edu.cn/showproblem.php?pid=1702

#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int INVALID = pow(2, 32) - 1;
class myQueue {
    queue<int> target;
    int length = 0;

   public:
    int pop() {
        if (length == 0) {
            return INVALID;
        }
        length--;
        int buf = target.front();
        target.pop();
        return buf;
    }
    void push(int num) {
        length++;
        target.push(num);
    }
};

class myStack {
    stack<int> target;
    int length = 0;

   public:
    int pop() {
        if (length == 0) {
            return INVALID;
        }
        length--;
        int buf = target.top();
        target.pop();
        return buf;
    }

    void push(int num) {
        length++;
        target.push(num);
    }
};

template <typename type>
void function(int cnt, type target) {
    for (int i = 0; i < cnt; i++) {
        string mode;
        int num;
        cin >> mode;
        if (mode == "IN") {
            cin >> num;
            target.push(num);
        } else if (mode == "OUT") {
            int ans = target.pop();
            if(ans != INVALID){
                cout << ans << '\n';
            }else{
                cout << "None" << '\n';
            }
        }
    }
}

void getMode() {
    int cnt;
    string mode;
    cin >> cnt;
    cin >> mode;
    if (mode == "FIFO") {
        myQueue target;
        function(cnt, target);
    } else if (mode == "FILO") {
        myStack target;
        function(cnt, target);
    }
}

int main() {
    int num = 0;
    cin >> num;
    for (int i = 0; i < num; i++) {
        getMode();
    }
    return 0;
}
