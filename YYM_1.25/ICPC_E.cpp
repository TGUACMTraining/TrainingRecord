#include <iostream>
#include <list>
#include <set>
#include <string>
using namespace std;
int main()
{
    int _test;
    cin >> _test;
    for (int test = 1; test <= _test; test++)
    {
        int a, b;
        list<string> A, B;
        string cache;
        set<string> _set;
        cin >> a >> b;
        for (int i = 0; i < a; i++)
        {
            getline(cin,cache);
            A.push_back(cache);
        }
        for (int i = 0; i < b; i++)
        {
            getline(cin,cache);
            B.push_back(cache);
        }
        list<string>::iterator a_, b_;
        for (a_ = A.begin(); a_ != A.end(); a_++)
        {
            for (b_ = B.begin(); b_ != B.end(); b_++)
            {
                _set.insert(*a_+*b_);
            }
        }
        cout<<"Case "<<test<<":"<<" "<<_set.size()<<endl;
    }
}