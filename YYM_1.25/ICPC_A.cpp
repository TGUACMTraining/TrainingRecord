#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
vector<int> woods[30];
int n;
pair<int, int> find(int t)
{
    for (int i = 0; i < n; i++)
    {
        int stop = woods[i].size();
        for (int j = 0; j < stop; j++)
        {
            if ((woods[i])[j] == t)
            {
                return make_pair(i, j);
            }
        }
    }
}
void clean(pair<int, int> a)
{
    int stop = woods[a.first].size();
    for (int i = a.second + 1; i < stop; i++)
    {
        int n;
        woods[n = (woods[a.first])[i]].push_back(n);
    }
    woods[a.first].resize(a.second + 1);
}
void move_a_onto_b(int a_, int b_)
{
    pair<int, int> a, b;
    a = find(a_);
    b = find(b_);
    if (a.first == b.first)
        return;
    clean(a);
    clean(b);
    woods[b.first].push_back((woods[a.first])[a.second]);
    woods[a.first].pop_back();
}
void move_a_over_b(int a_, int b_)
{
    pair<int, int> a, b;
    a = find(a_);
    b = find(b_);
    if (a.first == b.first)
        return;
    clean(a);
    woods[b.first].push_back((woods[a.first])[a.second]);
    woods[a.first].pop_back();
}
void pile_a_onto_b(int a_, int b_)
{
    pair<int, int> a, b;
    a = find(a_);
    b = find(b_);
    if (a.first == b.first)
        return;
    clean(b);
    woods[b.first].insert(woods[b.first].end(), woods[a.first].begin() + a.second, woods[a.first].end());
    woods[a.first].resize(a.second);
}
void pile_a_over_b(int a_, int b_)
{
    pair<int, int> a, b;
    a = find(a_);
    b = find(b_);
    if (a.first == b.first)
        return;
    woods[b.first].insert(woods[b.first].end(), woods[a.first].begin() + a.second, woods[a.first].end());
    woods[a.first].resize(a.second);
}
bool all(char move__pile, int a, char onto__over, int b)
{
    if (a == b)
        return true;
    switch (move__pile)
    {
    case 'm':
        switch (onto__over)
        {
        case 'n':
            move_a_onto_b(a, b);
            break;
        case 'v':
            move_a_over_b(a, b);
            break;
        }
        return true;

    case 'p':
        switch (onto__over)
        {
        case 'n':
            pile_a_onto_b(a, b);
            break;
        case 'v':
            pile_a_over_b(a, b);
            break;
        }
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        woods[i].push_back(i);
    }
    string move_pile, onto_over;
    int a, b;
    while (cin >> move_pile, move_pile != "quit")
    {
        cin >> a >> onto_over >> b;
        all(move_pile[0], a, onto_over[1], b);
        // print();
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int j = 0; j < woods[i].size(); j++)
        {
            cout << " " << (woods[i])[j];
        }
        cout << endl;
    }
    return 0;
}