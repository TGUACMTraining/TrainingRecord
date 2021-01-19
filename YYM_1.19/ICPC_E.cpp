/*
Consider a three-parameter recursive function w(a, b, c):
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
1
if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
w(20, 20, 20)
if a < b and b < c, then w(a, b, c) returns:
w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
otherwise it returns:
w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
This is an easy function to implement. The problem is, if implemented directly, for moderate values of a, b and c (for example, a = 15, b = 15, c = 15), the program takes hours to run because of the massive recursion.
*/
#include <iostream>
#include<cstdio>
using namespace std;
int help[20][20][20] = {0};
int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return help[0][0][0];
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    else if (help[a][b][c])
        return help[a][b][c];
    else
    {
        help[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return help[a][b][c];
    }
}
int main()
{
    help[0][0][0]=1;
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==b&&b==c&&c==-1)break;
        printf("w(%d,%d,%d) = %d\n",a,b,c,w(a,b,c));
    }
}