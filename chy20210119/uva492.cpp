#include<bits/stdc++.h> 
using namespace std;
char a[10005];
int pdzm(char c)//判断是否字母 
{
    if(c>='a'&&c<='z')
        return 1;
    if(c>='A'&&c<='Z')
        return 1;
    return 0;
}
int pdyy(char c)//判断是否元音 
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return 1;
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return 1;
    return 0;
}
int main()
{
    while(gets(a))
    {
        int s=0,t=0;//s代表当前字母,t代表单词长度. 
        while(a[s])
            if(!pdzm(a[s])) 
            {
                cout<<a[s++]; 
                t=s;
            }
            //不是字母就输出它. 
            else 
                if(pdzm(a[t]))
                    t++;
            //是字母就记录长度 
            else //如果是辅音开头把单词的开头放到最后，然后后加上ay后缀即可。
            {
                if(!pdyy(a[s]))
                {
                    for(int i=s+1;i<t;i++)cout<<a[i];
                    cout<<a[s];
                }
                else 
                    for(int i=s;i<t;i++)
                        cout<<a[i];
                cout<<"ay";
                s=t;
            }
        cout<<endl;
    }
    return 0;
}
