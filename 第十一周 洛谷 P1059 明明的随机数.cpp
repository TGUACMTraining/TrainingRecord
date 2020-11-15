#include<stdio.h>//该题的关键是解决“查重”和“排序” 
int main()
{
	int n,m,a[1001]={0},count=0;//初始化为0，方便后续查重及排序 
    scanf("%d",&n);//随机数个数 
    //录入数据的同时进行查重 
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&m);
    	if(a[m]==0)//查重 
    	{
    		a[m]=m;
    		count++;//计数器 
		}
	}
	printf("%d\n",count);
	//逐个排查，只要非零，就输出，实现排序 
	for(int i=0;i<1001;i++)
	if(a[i]!=0)
	printf("%d ",a[i]);
	return 0;
}
