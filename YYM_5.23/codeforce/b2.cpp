#include <iostream>
using namespace std;
int main()
{
    int t;
    int n;
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        char arr[(int)1e3 + 10] = "";
        cin >> arr;
        int cnt = 0;
        int os = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            if (arr[i] == '0' && arr[j] == '0')
            {
                os++;
            }
            if (arr[i] != arr[j])
            {
                cnt++;
            }
        }
        int alice, bob;
        alice = bob = 0;

        if (os != 0)
        {
            if ((n & 1) && arr[(n) / 2] == '0')cnt++;
            if(cnt != 0){
                bob = 1000000;
            }
            else{
                alice=1000000;
            }
        }
        else 
        {
            bob += cnt;
            if ((n & 1) && arr[(n) / 2] == '0')alice++;
        }
        if (alice == bob)
        {
            cout << "DRAW" << endl;
        }
        else if (alice > bob)
        {
            cout << "BOB" << endl;
        }
        else if (alice < bob)
        {
            cout << "ALICE" << endl;
        }
    }
}