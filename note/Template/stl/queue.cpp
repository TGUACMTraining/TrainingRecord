#include<queue>
using namespace std;
int main(){
    queue<int> a;
    a.push(1);
    int frontelement=a.front();
    a.push(2);
    a.pop();
    a.empty();
    a.size();
}