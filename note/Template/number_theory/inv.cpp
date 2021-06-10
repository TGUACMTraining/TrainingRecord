int exgcd(int a,int b,int &x,int &y);
int inv(int a,int n)//a关于n的逆元
{
    int gcd,x,y;
    gcd=exgcd(a,n,x,y);
    if(gcd==1)
        return ((x%n)+n)%n;//保证最小正整数
    else
        return -1;//没有互质，不存在逆元
}
