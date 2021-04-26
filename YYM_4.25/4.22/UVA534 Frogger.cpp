#include <iostream>
#include <cstdio>
#include <cstring>

#include <cmath>
using namespace std;
int n;
const int limit = 210;
double dis[limit][limit];
int position[limit][2];
int main()
{
    int cnt = 0;
    while (cin >> n, n)
    {

        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            position[i][0] = x;
            position[i][1] = y;
            for (int j = 0; j < i; j++)
            {
                dis[i][j] = dis[j][i] = pow(pow(position[i][0] - position[j][0], 2) + pow(position[i][1] - position[j][1], 2), 0.5);
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    double cache = max(dis[i][k], dis[k][j]);
                    if (dis[i][j] > cache)
                    {
                        dis[i][j] = dis[j][i] = cache;
                    }
                }
            }
        }
        cout << "Scenario #" << ++cnt << endl;
        printf("Frog Distance = %.3lf\n\n", dis[0][1]);
    }
}