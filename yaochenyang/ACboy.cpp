#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
int main()
{
	int a,b,c;
	char x[100],y[100];
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d%s",&b,x);	
		if(x[2]=='F')
		{
			queue <int> q;
			for(int i=1;i<=b;i++)
			{
				scanf("%s",y);
				if(y[0]=='I')
				{
					scanf("%d",&c);
					q.push(c);
				}
				else
				{
					if(q.empty())	
						printf("None\n");
					else
					{
						printf("%d\n",q.front());
						q.pop();
					}					
				}
			}
		}
		if(x[2]=='L')
		{
			stack <int> s;
			for(int i=1;i<=b;i++)
			{
				scanf("%s",y);
				if(y[0]=='I')
				{
					scanf("%d",&c);
					s.push(c);
				}
				else
				{
					if(s.empty())
						printf("None\n");
					else
					{
						printf("%d\n",s.top());
						s.pop();
					}					
				}
			}
		}	
	}
	return 0;		
}	

