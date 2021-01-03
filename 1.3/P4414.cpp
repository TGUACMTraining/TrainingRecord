#include<stdio.h>
int main()
{
	int a[5],temp;char b[5];
	for(int i=1;i<=3;i++)
	{
		scanf("%d",&a[i]);
	}
	//排序
	if(a[1]>a[2])
	{
		temp=a[1];
		a[1]=a[2];
		a[2]=temp;
	}
	if(a[1]>a[3])
	{
		temp=a[1];
		a[1]=a[3];
		a[3]=temp;
	}
	if(a[2]>a[3])
	{
		temp=a[2];
		a[2]=a[3];
		a[3]=temp;
	}
	while(getchar()!='\n') continue;
	scanf("%s",b);
	for(int i=0;i<3;i++)
	{
		printf("%d ",a[b[i]-64]);
	}
	return 0;
}
//https://www.luogu.com.cn/problem/P4414
//P4414 [COCI2006-2007#2] ABC
//思路：对录入的数据从大到小排完序后，再录入
//字母，通过对字母作差得分别得到0，1，2并将
//其作为数组的下标，从而实现按字母顺序输出。
