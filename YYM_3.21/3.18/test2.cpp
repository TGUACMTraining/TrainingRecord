#include <cstdio>
#include <bitset>
#include <iostream>
#define year (a*1000+b*100+c*10+d)
using namespace std;

int read()
{
    int x=0,f=1;char c=getchar();
    while (c<'0' || c>'9'){if (c=='-')f=-1;c=getchar();}
    while (c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-48;c=getchar();}
    return x*f;
}

const int MAXN=10005;
const int sum[]={0,229,103,107,113,131,211,223,307,311,313,317,331,419,503,523,607,613,617,619,719,811,823,829,907,911,919,929,1013,1019,1031,1103,1117,1123,1129,1213,1217,1223,1229,1231};
													//我把满足条件的日月打了表，这打表代码特简单就不给出了
string s;
int len,ans;
int prim[MAXN],tot;
int l[10],r[10];
bitset<MAXN> v;

inline void prime()									//线性筛
{
    v[1]=true;
    for (int i=2;i<=MAXN;i++)
    {
        if (!v[i]) prim[++tot]=i;
        for (int j=1;j<=tot;j++)
        {
            if (i*prim[j]>=MAXN) break;
            v[i*prim[j]]=true;
            if (i%prim[j]==0) break;
        }
    }
}

inline bool ok(int x)								//判断是否满足当前字符串
{
    int w=8;
    while (x>0)
    {
        if (l[w]>(x%10)||r[w]<(x%10)) return false;
        w--;x/=10;
    }
    if (w>=5)
        for (int i=5;i<=w;i++) if (l[i]!=0) return false;
    return true;
}

inline bool is_(int n)
{
    for (int i=1;i<=tot;i++)
        if (n%prim[i]==0) return false;
    return true;
}

int main()
{
    prime();
    int cas,i,a,b,c,d;cas=read();
    while (cas--)
    {
        cin>>s;ans=0;bool flag=true;
        for (i=0;i<8;i++)
        {
            if (s[i]!='-') l[i+1]=r[i+1]=s[i]-48,flag=false;
            else l[i+1]=0,r[i+1]=9;
        }
        if (flag) printf("%d\n",55157);
        else 
        {
            for (i=1;i<=39;i++)
                if (ok(sum[i]))
                    for (a=l[1];a<=r[1];a++)
                        for (b=l[2];b<=r[2];b++)
                            for (c=l[3];c<=r[3];c++)
                                for (d=l[4];d<=r[4];d++)
                                {
                                    if (i==1)
                                    {
                                        if ((year%4==0)&&((year%100!=0)||(year%400==0)));//闰年特判
                                        else continue;	
                                    }
                                    if (year!=0&&is_(year*10000+sum[i])) ans++;
                                }
            printf("%d\n",ans);
        }
    }
    return 0;
}