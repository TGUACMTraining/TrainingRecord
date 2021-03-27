#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    while (cin >> a)
    {
        stringstream ss;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '5')
                a[i] = ' ';
        }
        ss << a;
        int n;
        vector<int> arr;
        while (ss >> n)
        {
            arr.push_back(n);
        }
        sort(arr.begin(), arr.end());
        int flag=0;
        for (int t : arr)
        {
            if(flag)
            printf(" ");
            cout << t ;
            flag=1;
        }
            printf("\n");
    }
}