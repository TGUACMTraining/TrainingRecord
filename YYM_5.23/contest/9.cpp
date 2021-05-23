#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int NT[(int)1e6];
char str[(int)1e6];
char mod[(int)1e6];
int n,m;
long long ans ;



void getNext()
{
    m = strlen(mod);
    NT[0] = NT[1] = 0;
    for(int i = 1;i < m;i ++)
    {
        int j = NT[i];
        while(j && mod[i] != mod[j]) j = NT[j];
        if(mod[i] == mod[j]) NT[i + 1] = j + 1;
        else NT[i+1] = 0;
    }

}

void find()
{
    getNext();
    int j = 0;
    for(int i = 0;i < n;i ++)
    {
        while(j && str[i] != mod[j]) j = NT[j],ans += j;
        if(str[i] == mod[j]) j ++,ans ++;
        if(j == m) j = NT[m-1],i --;
    }
}

int main()
{
    int q;
    scanf("%d %d",&n,&q);
    getchar();
    scanf("%s",str);
    while(q --)
    {
        getchar();
        scanf("%s",mod);
        find();
        printf("%lld\n",ans);
        ans = 0;
    }
}