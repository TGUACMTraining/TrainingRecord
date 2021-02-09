    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    bool com(int a, int b)
    {
        return a > b;
    }
    int main()
    {
        int n, m;
        while (!(cin >> n >> m).eof())
        {
            int *arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            sort(arr, arr + n, com);
            cout<<arr[0];
            for (int i = 1; i < m; i++)
            {
                cout << " "<< arr[i] ;
            }
            cout << endl;
        }
    }