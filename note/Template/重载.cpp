#include <stdio.h>
#include <iostream>
using namespace std;
void print(int a, int b = 0)
{ //b默认为0
    cout << a << " " << b << endl;
}
int main()
{
    print(5);
    print(2, 3);
    return 0;
}