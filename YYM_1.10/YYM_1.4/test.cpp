#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
	int T,l,i,j,h,t,small;
	int q[505],qq[605];
	char s[505];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		l=strlen(s);
		j=0;
		for(i=0;i<l;i++)
		{
		q[i]=s[i]-'0';
		if(q[i]!=0)
		j=1;
	    }
	    if(!j)
	    {
	    	printf("0\n");
	    	continue;
	    }
	    small=INF;
	    j=0;
	    for(i=0;i<l;i++)
	    if(q[i]<=small&&q[i]!=0)
	    small=q[i],j=i;
		qq[200]=q[0];
		h=t=200;
		if(j!=0)
		{
		for(i=1;i<l;i++)
		if(i==j)
		break;
		else if(q[i]<=qq[h])
		qq[--h]=q[i];
		else
		qq[++t]=q[i];
	    }
		if(j!=0)
		printf("%d",small);
		for(i=h;i<=t;i++)
		printf("%d",qq[i]);
		for(i=j+1;i<l;i++)
		printf("%d",q[i]);
		printf("\n");
	}
	return 0;
}