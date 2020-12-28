#include<stack>
#include<iostream>
using namespace std;
int main(){
    stack<int> a;
    a.push(1);
    int topelement=a.top();
    a.push(2);
    a.pop();
    a.empty();
    a.size();
}