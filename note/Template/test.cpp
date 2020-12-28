// list::emplace
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> li = {0, 1, 2, 3};
    list<int>::iterator p;
    p = li.begin();
    cout << *(li.end()) << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << *p;
        if (p == li.begin())
        {
            cout << "       here";
        }
        cout << endl;
        p++;
    }
    for (int i = 0; i < 30; i++)
    {
        cout << *p;
        if (p == li.begin())
        {
            cout << "       here";
        }
        cout << endl;
        p--;
    }
    cout << '\n';
    return 0;
}