#include <bits/stdc++.h>
using namespace std;
int height[100][100];
int length[100][100];
int r, c;
int gaodu(int x, int y)
{
    if (x >= 0 && x < r && y >= 0 && y < c)
    {
        return height[x][y];
    }
    else
    {
        return -1;
    }
}
enum
{
    shang,
    xia,
    zuo,
    you
};
int change[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},

};
int solve_the_length(int x, int y)
{
    if (length[x][y] + 1)
    {
        return length[x][y];
    }
    int flag = 1;
    stack<int> go;
    for (int i = 0; i < 4; i++)
    {
        if (height[x][y] < gaodu(x + change[i][0], y + change[i][1]))
        {
            flag = 0;
            go.push(solve_the_length(x + change[i][0], y + change[i][1]));
        }
    }
    if (flag)
    {
        length[x][y] = 1;
        return 1;
    }
    int biggest = 0;
    while (!go.empty())
    {
        biggest = max(go.top(), biggest);
        go.pop();
    }
    length[x][y] = biggest + 1;
    return length[x][y];
}
int main()
{
    cin >> r >> c;
    memset(height, -1, sizeof(height));
    memset(length, -1, sizeof(length));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> height[i][j];
        }
    }
    int max_=0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            max_=max(solve_the_length(i,j),max_);
        }
    }
    cout<<max_<<endl;
}