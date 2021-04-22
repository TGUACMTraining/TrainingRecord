#include <iostream>
using namespace std;
const int limit = (int)1e5 + 10;
char a[limit];
char b[limit];
int kmp[limit];
int la;
int lb;

void print_str(int i,int j){
    for(int t=2;t<=i;t++){
        cout<<a[t];
    }cout<<endl;
    cout<<string(i-j-2,' ');
    for(int t=1;t<=j+1;t++){
        cout<<b[t];
    }cout<<endl;
    cout<<string(i-j-2,' ');
    for(int t=1;t<=20;t++){
        cout<<kmp[t];
    }cout<<endl;
    cout<<endl;
}
int main()
{
    cin >> a + 1 >> b + 1;
    la = strlen(a + 1);
    lb = strlen(b + 1);
    int j = 0;
    for (int i = 2; i <= lb; i++)
    {
        while (j > 0 && b[j + 1] != b[i])
        {
            print_str(i,j);

            j = kmp[j];
        }
        if (b[j + 1] == b[i]){
            print_str(i,j);
            j++;
        }
            print_str(i,j);

        kmp[i] = j;
    }
    for (int i = 1; i <= la; i++)//正在匹配的位置(a)
    {
        while (j > 0 && b[j + 1] != a[i])//匹配的前一个位置(b)
        {
            j = kmp[j];//往回走
        }
        if (b[j + 1] == a[i])
            j++;//准备匹配下一个字符
        if (j == lb)//匹配成功
        {
            cout << i - j + 1 << endl;
            j = kmp[j];
        }
    }
    return 0;
}