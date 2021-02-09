
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--) {
        string a, b;
        map<string, vector<string> > m;
 
        scanf("%d", &n);
        while(n--) {
            cin >> a;
 
            b = a;
            transform(b.begin(), b.end(), b.begin(), ::toupper);
            sort(b.begin(), b.end());
 
            m[b].push_back(a);
        }
 
        for(;;) {
            cin >> a;
            if(a == "END")
                break;
 
            b = a;
            transform(b.begin(), b.end(), b.begin(), ::toupper);
            sort(b.begin(), b.end());
 
            int len = m[b].size();
            cout << "Anagrams for: " << a << endl;
            if(len == 0)
                cout << "No anagrams for: " << a << endl;
            else {
                int num = 0;
                for(int i = 0; i < len; i++)
                    cout << "  " << ++num << ") " << m[b][i] << endl;
            }
        }
 
        if(t)
            printf("\n");
    }
 
    return 0;
}
