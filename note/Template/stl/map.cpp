#include <map>
#include <string>
using namespace std;
int main()
{
    pair<int, int> origin;
    origin = make_pair(0, 0);
    origin.first == origin.second;

    map<string, int> arr = {{"aaa", 1}, {"bbb", 2}};
    pair<string, int> ori = {"ccc", 3};
    arr.insert(ori);
    arr["aaa"]++;
    arr.erase("ccc");
}