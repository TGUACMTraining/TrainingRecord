#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool cmp(vector<int> A, vector<int> B)
{
    if (A.size() != B.size())   return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i --)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}

vector<int> sub(vector<int> A, vector<int> B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++)
    {
        t = A[i] - t;
        if (i < B.size())   t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)  t = 1;
        else    t = 0;
    }
    
    while(C.size() > 1 && C.back() == 0)    C.pop_back();
    return C;
}

int main(void)
{
    string s1, s2;
    vector<int> A, B;
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; i --)   A.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i --)   B.push_back(s2[i] - '0');
    
    if (cmp(A,B))
    {
        auto C = sub(A,B);
        for (int i = C.size() - 1; i >= 0; i --)    printf("%d", C[i]);
    }
    else
    {
        printf("-");
        auto C = sub(B,A);
        for (int i = C.size() - 1; i >= 0; i --)    printf("%d", C[i]);
    }
    return 0;
}
