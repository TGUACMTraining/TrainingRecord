#include <iostream>
using namespace std;
int main()
{
    int row, cl;
    cin >> row >> cl;
    if (!(row & 1 || cl & 1))
    {
        printf("NO");
    }
    else
    {
        printf("YES\n");
        if (row & 1)
        {
            for (int i = 1; i <= row; i++)
            {
                if (i & 1)
                {
                    for (int j = 1; j <= cl; j++)
                    {
                        if (j == cl && i == row)
                            continue;
                        if (i == 1 && j == 1)
                            continue;
                        else
                        {
                            printf("%d %d\n", i, j);
                        }
                    }
                }
                else
                {
                    for (int j = cl; j > 0; j--)
                    {
                        if (j == cl && i == row)
                            continue;
                        if (i == 1 && j == 1)
                            continue;
                        printf("%d %d\n", i, j);
                    }
                }
            }
        }
        else
        {
            for (int j = 1; j <= cl; j++)
            {
                if (j & 1)
                    for (int i = 1; i <= row; i++)
                    {

                        if (i == row && j == cl)
                            continue;
                        if (i == 1 && j == 1)
                            continue;
                        printf("%d %d\n", i, j);
                    }
                else
                {
                    for (int i = row; i > 0; i--)
                    {

                        if (i == row && j == cl)
                            continue;
                        if (i == 1 && j == 1)
                            continue;
                        printf("%d %d\n", i, j);
                    }
                }
            }
        }
    }
}