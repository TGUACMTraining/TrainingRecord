int exgcd(int a,int b,int &x,int &y);
int inv(int a,int n)//a����n����Ԫ
{
    int gcd,x,y;
    gcd=exgcd(a,n,x,y);
    if(gcd==1)
        return ((x%n)+n)%n;//��֤��С������
    else
        return -1;//û�л��ʣ���������Ԫ
}
