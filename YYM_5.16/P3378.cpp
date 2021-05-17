#include <iostream>
#include <queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int op;
    int x;
    cin >> op;
    switch (op) {
      case 1:
        cin >> x;
        q.push(x);
        break;
      case 2:
        cout << q.top() << endl;
        break;
      case 3:
        q.pop();
        break;
    }
  }
}