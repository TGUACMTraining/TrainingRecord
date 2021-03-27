#include <iostream>
#include <list>
#include <cstring>
#include <cstdio>
using namespace std;
int p, q;
bool visited[30][30];
int move_point[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, -1}, {-2, 1}, {2, -1}};
int con = 1;
list<pair<int, int>> path_cache;
list<pair<int, int>> path;

void dfs(int x, int y)
{
    if (con = 1)
    {
        int flag = 0;
        for (int i = 0; i < 8; i++)
        {
            int x_, y_;
            x_ = x + move_point[i][0];
            y_ = y + move_point[i][1];
            if (x_ > 0 && p >= x_ && y_ > 0 && y_ <= q && visited[x_][y_] == 0)
            {
                visited[x_][y_] = 1;
                path_cache.push_back(make_pair(x_, y_));
                flag = 1;
                dfs(x_, y_);
                if (con == 0)
                    break;
                visited[x_][y_] = 0;
                path_cache.pop_back();
            }
        }
        if (flag == 0)
        {
            int visit = 1;
            for (int i = 1; i <= p; i++)
            {
                for (int j = 1; j <= q && visit; j++)
                {
                    visit = visit && visited[i][j];
                }
            }
            if (visit)
            {
                path = path_cache;
                con = 0;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int b = 1; b <= n; b++)
    {
        cin >> q >> p;
        cout << "Scenario #" << b << ":" << endl;
        memset(visited, 0, sizeof(visited));
        con = 1;
        path.clear();
        path_cache.clear();
        for (int i = 1; i <= (p + 1) / 2; i++)
        {
            for (int j = 1; j <= (q + 1) / 2; j++)
            {
                if (con)
                {
                    visited[i][j] = 1;
                    path_cache.push_back(make_pair(i, j));
                    dfs(i, j);
                    visited[i][j] = 0;
                    path_cache.pop_back();
                }
            }
        }
        if (con == 0)
        {
            for (list<pair<int, int>>::iterator a = path.begin(); a != path.end(); a++)
            {
                printf("%c%d", 'A' - 1 + (*a).first, (*a).second);
            }
            cout << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }
}