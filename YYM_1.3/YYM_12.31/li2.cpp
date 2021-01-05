#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    const int key = 13;
    string str = {""};
    vector<unsigned long long> str_hash = {0};
    unsigned long long HASH(int begin)
    {
        int length = str_hash.size();
        int to = str.length() - begin;
        int times = to - length + 1;
        if (times > 0)
        {
            while (times--)
            {
                unsigned long long t = (*(str_hash.end() - 1));
                t *= key;
                t += (unsigned long long)str[str.length() - str_hash.size()];
                str_hash.push_back(t);
            }
            return (*(str_hash.end() - 1));
        }
        else
            return str_hash[str.length() - begin];
    }
    unsigned long long HASH(int begin, int end)
    {

        if (begin > end)
            return 0;
        unsigned long long ret = HASH(begin);

        ret -= HASH(end) * (unsigned long long)pow(key, end - begin);
        return ret;
    }
} my_string;
int main()
{
    my_string str;
    cin >> str.str;
    int n;
    cin >> n;
    while (n--)
    {
        my_string str2;
        int flag = 0;
        cin >> str2.str;
        int i = str2.str.end() - str2.str.begin();
        int len = i;
        for (; i >= 0; i--)
        {
            unsigned long long str_hash_left = str.HASH(0, i);
            unsigned long long str_2_hash_left = str2.HASH(0, i);
            unsigned long long str_hash_right = str.HASH(i + 1, len);
            unsigned long long str_2_hash_right = str2.HASH(i + 1, len);
            if (str_2_hash_left == str_hash_left && str_2_hash_right == str_hash_right)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}