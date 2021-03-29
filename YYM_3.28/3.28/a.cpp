#include <iostream>
#include <algorithm>
using namespace std;
int arr[1100];
int main()
{
    int n;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        cnt+=arr[i]-arr[i-1]-1;
    }
    cout<<cnt<<endl;
}