#include <bits/stdc++.h>
using namespace std;
int main()
{
    FILE *a, *b;
    a = fopen("a.txt", "r+");
    b = fopen("b.txt", "r+");
    if (a && b)
    {
        char x[150]={0};
        char y[150]={0};
        int i = 5;
        while (i--)
        {

            fscanf(a, "%s", x);
            fscanf(b, "%s", y);
            string x_ = x;
            string y_ = y;
            if (x == y)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong\n");
                printf("%s\n%s\n",x,y);  
            }
        }
        fclose(a);
        fclose(b);
    }
    return 0;
}