//B.Hills And Valleys
//
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sum=0;
		scanf("%d",&n);
		int a[300009]={0};
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		if(n<6) printf("0\n");
		else
		{
			int flag1=0,flag2=-1,flag3=0,flag4=0,flag5=0;
			for(int i=0;i<n-2;i++)
			{
				if((a[i]>a[i+1]&&a[i+2]>a[i+1])||(a[i]<a[i+1]&&a[i+2]<a[i+1]))
				{
					sum++;flag2=i;//flag2记录有hill或valley时i的值
				}
				if(((a[i]>a[i+1]&&a[i+2]>a[i+1])||(a[i]<a[i+1]&&a[i+2]<a[i+1]))&&flag2==i)
				{
					flag1++;//记录hill与valley的连续情况
				}
				else flag1=0;//如果flag2不一致，即hill和valley不连续
				if(flag1==3) flag3=3;//flag立即记录有连续的（多少不是关键，有即可）
				if(flag1==2) flag4=2;
				if(flag1==1) flag5=1;
			}
			//根据反馈的flag值进行微调。
			if(sum>=2)
			{
				if(flag3)
				printf("%d\n",sum-3);
				else if(flag4)
				printf("%d\n",sum-2);
				else if(flag5)
				printf("%d\n",sum-1);
			}
			else printf("0\n");
		}
	}
	return 0;
}
//我们先遍历一次输入数据，统计hill和valley的数目
//关键：识别hill和valley相邻的有多少个
//容易发现，若要调整到最小，最好的方法是将谷底或
//峰顶a[i]的数值调整到与a[i-1]或a[i+1]相等
//思路：(后来被证明两个时错误)
//如果只有单个hill或valley，没有连续的，最后只需sum-1
//如果最多只有两个hill或valley连续，最后只需sum-2；
//如果最多只有三个或三个以上连续，最后只需sum-3；
//发现错误：若n=6，a[6]={1,2,3,1,2,3},则只能消去1个hill或valley
//总结：所以，发现需要考虑的情况更为复杂，于是果断放弃。

//查看了官方题解，大体思路如下
//第一部分一样，先遍历统计hill和valley的数目，但是不同的是
//它在遍历的同时将数组处理为一个等价数组，处理思路如下：
//先定义一个长度为n的数组并初始化为0，之后假定j为谷底或丘顶，
//则有 若aj为hill或valley，则对应的arr[j]赋值为1。最后获得
//一个能够反应数组元素是否是hill或valley的等价类
//之后对获得的总数进行微调。
//容易发现，若要调整到最小，最好的方法是将谷底或
//峰顶a[i]的数值调整到与a[i-1]或a[i+1]相等，但是与我方法不同的是
//它直接进行调整，并将调整后的总数更新并不断与后续的调整后的数值比较，
//从而得出最小的值
//具体操作见下方代码(有注释)

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5;
int a[N], n;

int isValley(int i) {
    return (i>0 && i<n-1 && a[i] < a[i-1] && a[i]<a[i+1]);
}

int isHill(int i) {
    return (i>0 && i<n-1 && a[i] > a[i-1] && a[i]>a[i+1]);
}

int solveTestCase() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];

    int is[n] = {};
    int s = 0;
//遍历的同时计算hill和valley总数并生成等效数组is[n];
    for (int i=1;i<n-1;i++) {
        if (isHill(i) || isValley(i))
            is[i] = 1, s++;
    }
//对计算结果进行调整
    int ans = s;
//再次遍历，计算并比较经过修改后的值，并将最小值赋给ans
    for (int i=1;i<n-1;i++) {
        int temp = a[i];//将a[i]中的值挖出来暂存到temp中
        a[i] = a[i-1];//使a[i]等于其左侧的值
        //检验修改后的值与原先的值相比哪个更小
        ans = min(ans, s - is[i-1] - is[i] - is[i+1] + isHill(i-1) + isValley(i-1) + isHill(i) + isValley(i) + isHill(i+1) + isValley(i+1));
//这里-is[i-1]-is[i]-is[i+1]其实相当于将这三个点的等效值清零然后重新计算。
//后面调用了六次函数则是计算i-1，i，i+1这三个点的等效值。ans完成第一次更新。
		a[i] = a[i + 1];//使得[i]等于右侧的值
        //同第一次检验
        ans = min(ans, s - is[i-1] - is[i] - is[i+1] + isHill(i-1) + isValley(i-1) + isHill(i) + isValley(i) + isHill(i+1) + isValley(i+1));
        a[i] = temp;//将最初挖出来的数值填回去，使数组a[]恢复原状，以便下次比较更新。
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solveTestCase();
}
