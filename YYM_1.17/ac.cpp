#include<cstdio>
#include<cstring>
using namespace std;
int prime[10000005]={0};
int a[100005],b[100005];
int ap[10000005],bp[10000005];
void check(int *x,int *y,int len)//分解因子
{
    for(int i=0;i<len;++i)
        for(int j=x[i];j>1;j/=prime[j])
           y[prime[j]]++;//因子数+1
}
void print(int *x,int *y,int len)
{
    int cnt;
    for(int i=0;i<len;++i)
    {
        cnt=1;
        for(int j=x[i];j>1;j/=prime[j])
            if(y[prime[j]]>0) y[prime[j]]--;
            else              cnt*=prime[j];
        if(i==0) printf("%d",cnt);
        else     printf(" %d",cnt);
    }
    puts("");
}
int main()
{
    int n,m;
    prime[2]=0;
    for(int i=2;i<=10000000;++i)
        if(!prime[i])
        {
            prime[i]=i;
            for(int j=2*i;j<=10000000;j+=i)
                prime[j]=i;
        }
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",a+i);
    for(int i=0;i<m;++i) scanf("%d",b+i);
    check(a,ap,n);check(b,bp,m);
    printf("%d %d\n",n,m);
    print(a,bp,n);print(b,ap,m);
    return 0;
}