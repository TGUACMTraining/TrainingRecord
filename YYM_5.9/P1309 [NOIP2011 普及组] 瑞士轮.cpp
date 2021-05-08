#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct x
{
    int number;
    int power;
    int score;
} arr[(int)1e6 + 10];
int n, r, q;
bool cmp(x &a, x &b)
{
    if (a.score == b.score)
    {
        return a.number < b.number;
    }
    return a.score > b.score;
}
char *p;
inline void read(register int &x)
{
    x = 0;
    while (!isdigit(*p))
        ++p;
    while (isdigit(*p))
        x = x * 10 + (*p & 15), ++p;
}
x arrwin[(int)5e5 + 10];
x arrlost[(int)5e5 + 10];
// void dbg()
// {
//     cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i].number << " " << arr[i].score << " " << arr[i].power << endl;
//     }
//     cout << "win:" << endl;
//     for (int i = 0; i < n / 2; i++)
//     {
//         cout << arrwin[i].number << " " << arrwin[i].score << " " << arrwin[i].power << endl;
//     }
//     cout << "lost:" << endl;
//     for (int i = 0; i < n / 2; i++)
//     {
//         cout << arrlost[i].number << " " << arrlost[i].score << " " << arrlost[i].power << endl;
//     }
//     cout << endl;
// }
int main()
{
    // freopen("P1309_2.in", "r", stdin);
    p = new char[(int)2e6],
    fread(p, 1, (int)2e6 - 1, stdin);
    read(n);
    read(r);
    read(q);
    n *= 2;
    for (int i = 0; i < n; i++)
    {
        read(arr[i].score);
        arr[i].number = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        read(arr[i].power);
    }
    sort(arr, arr + n, cmp);
    while (r--)
    {
        for (int i = 0; 2 * i < n; i++)
        {
            if (arr[2 * i].power > arr[2 * i + 1].power)
            {
                arrwin[i] = arr[2 * i];
                arrlost[i] = arr[2 * i + 1];
            }
            else
            {
                arrwin[i] = arr[2 * i + 1];
                arrlost[i] = arr[2 * i];
            }
            arrwin[i].score++;
        }
        // dbg();
        int i = 0;
        int j = 0;
        int t = 0;
        while (i < n / 2 && j < n / 2)
        {
            if (cmp(arrwin[i], arrlost[j]))
            {
                arr[t++] = arrwin[i++];
            }
            else
            {
                arr[t++] = arrlost[j++];
            }
        }
        while (i < n / 2)
        {
            arr[t++] = arrwin[i++];
        }
        while (j < n / 2)
        {
            arr[t++] = arrlost[j++];
        }
    }
    printf("%d", arr[q - 1].number);
}