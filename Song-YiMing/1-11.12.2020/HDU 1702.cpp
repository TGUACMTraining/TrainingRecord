#include<cstdio>

using namespace std;

int main()
{
	int m,n,temp;
	int l,r,arr[100010]={0};//数组用 
	bool b;					//0先进先出，1先进后出 
	char c[5];
	scanf("%d",&m);
	for(int t=1;t<=m;t++)
	{
		scanf("%d",&n);
		scanf("%s",c);
		if('F'==c[2]){
			b=0;
		}else b=1;
		l=1,r=0;				//r不越界，l>r时说明无元素 
		for(int i=1;i<=n;i++)
		{
			scanf("%s",c);
			if('I'==c[0]){
				scanf("%d",&arr[++r]);
			}else{
				if(l>r)printf("None\n");
				else{
					if(b){
						//先进后出
						printf("%d\n",arr[r--]);
					}else{
						printf("%d\n",arr[l++]);
					}
				}
			}
		}
	}
	
	return 0;
 } 
