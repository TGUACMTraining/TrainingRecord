#include<bits/stdc++.h>
// #define debug 
#ifdef debug
#define dbg(x) \
{\
    cout<<"online "<<__LINE__<<endl;\
    x;\
    cout<<"----------------"<<__LINE__<<endl;\
}
#else
#define dbg(x)
#endif
using namespace std;
const int q = 100010;
const int INF = 0x3f3f3f3f;
int ind = 0;
int height[q] = {0};
int length[q] = {0};
stack<int> *step;
int n=0;
int solve(bool (*cmp) (int ,int )){
    dbg()
    step=new stack<int>[ind+10]();
    for (int i = 0; i < ind; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (cmp(height[j] , height[i]))
            {
                if (length[j] > length[i])
                {
                    length[i] = length[j];
                    step[i] = step[j];
                }
            }
        }
        length[i]++;
        step[i].push(i);
    }
    int ans = 0;
    int p;
    for (int i = 0; i < ind; i++)
    {
        if (length[i] > ans)
            {ans = length[i];p=i;}
    } return p;
}
bool compare_greater(int a,int b){
    return a-b>=0;
}
bool compare_less(int a,int b){
    return a-b<0;
}

int main()
{
    int c;
    while (~scanf("%d",&c))
    {
        height[ind++]=c;
    }
    
    int i;
    i=solve(compare_greater);
    cout << length[i] << endl;
    delete [] step;
    memset(length,0,sizeof(length));
    i=solve(compare_less);
    cout<<length[i]<<endl;
}