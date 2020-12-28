#include<set>
using namespace std;
int main(){
    set<int> a;//自带去重的集合
    a.insert(1);
    a.find(1);
    a.erase(1);
    multiset<int> b;//可以有相同元素的集合
    b.insert(1);
    b.insert(1);
    b.count(1);
}