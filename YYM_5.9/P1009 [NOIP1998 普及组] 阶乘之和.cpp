#include <iostream>
#include<cstring>
using namespace std;
const int limit = 100;
struct NUM
{
    int arr[2 * limit];
    int &operator[](int i)
    {
        return arr[i];
    }
    NUM operator+(NUM n)
    {
        NUM number(0);
        for (int i = 0; i < limit; i++)
        {
            number[i] += arr[i] + n[i];
            if (number[i] / 10)
            {
                number[i + 1] += number[i] / 10;
                number[i] %= 10;
            }
        }
        return number;
    }
    NUM operator*(NUM n)
    {
        NUM number(0);
        for (int i = 0; i < limit; i++)
        {
            for (int j = 0; j < limit; j++)
            {
                number[i + j] += n[i] * arr[j];
            }
        }
        for (int i = 0; i < limit; i++)
        {
            number[i + 1] += number[i] / 10;
            number[i] %= 10;
        }
        return number;
    }
    NUM(int n)
    {
        memset(this->arr, 0, sizeof(arr));
        int index = 0;
        while (n)
        {
            arr[index++] += n % 10;
            n /= 10;
        }
    }
    void print()
    {
        int flag = 0;
        for (int i = limit; i >= 0; i--)
        {
            if (arr[i])
                flag = 1;
            if (flag)
                cout << arr[i];
        }
        if (flag == 0)
            cout << 0;
    }
};
int n;
int main()
{
    NUM ans(0), cache(1);
    cin>>n;
    for(int i=1;i<=n;i++){
        cache=cache*NUM(i);
        ans=ans+cache;
    }
    ans.print();
}