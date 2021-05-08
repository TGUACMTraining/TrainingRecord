#include <iostream>
using namespace std;
// #define dbg(x)                                 \
//     {                                          \
//         cout << "--line:" << __LINE__ << endl; \
//         x;                                     \
//         cout << "++line:" << __LINE__ << endl; \
//     }
#define dbg(x)
char *p;
inline void read(register int &x)
{
    while (!isdigit(*p))
        p++;
    x = 0;
    while (isdigit(*p))
        x = x * 10 + ((*p++) & 15);
}
int arr[(int)5e4 + 100];
int l, n, m;
bool judge(int x){
    int tot = 0;
    int i = 0;
    int now = 0;
    while (i < n){
        i++;
        if (arr[i] - arr[now] < x)
            tot++;
        else
            now = i;
    }
    dbg(
        cout<<tot<<endl;
    )
    if (tot > m)
        return false;
    else
        return true;
}
int bs(int min_, int max_)
{
    if (min_ == max_)
        return min_;
    int mid = (min_ + max_+1) / 2;

    if (judge(mid))
    {
        return bs(mid , max_);
    }
    else
    {
        return bs(min_, mid-1);
    }
}
int main()
{
    const int read_ = (int)4e6;
    p = new char[read_];
    fread(p, 1, read_, stdin);
    read(l);
    read(n);
    read(m);
    for (int i = 1; i <= n; i++)
    {
        read(arr[i]);
    }
    n++;
    arr[n] = l;
    dbg(for (int i = 0; i <= n; i++) {
        cout << arr[i] << endl;
    })
    if(n==1||m==0){
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,arr[i+1]-arr[i]);
        }
        cout<<ans<<endl;
    }else
        printf("%d", bs(0, l));
}