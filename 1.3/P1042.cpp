#include<bits/stdc++.h>
using namespace std;
const int N=30*3000;
char c;
int ans[N][10];
int main()
{
	while(cin>>c)
	{
		if((ans[ans[0][0]][1]>=11||ans[ans[0][0]][2]>=11)&&abs(ans[ans[0][0]][1]-ans[ans[0][0]][2])>=2) ans[0][0]++;
		if((ans[ans[1][0]][3]>=21||ans[ans[1][0]][4]>=21)&&abs(ans[ans[1][0]][3]-ans[ans[1][0]][4])>=2) ans[1][0]++;
		if(c=='E') break;
		if(c=='W')
		{
			ans[ans[0][0]][1]++;
			ans[ans[1][0]][3]++;
		}
		if(c=='L')
		{
			ans[ans[0][0]][2]++;
			ans[ans[1][0]][4]++;
		}
	}
	for(int i=0;i<=ans[0][0];i++)
		printf("%d:%d\n",ans[i][1],ans[i][2]);
	printf("\n");
	for(int i=0;i<=ans[1][0];i++)
		printf("%d:%d\n",ans[i][3],ans[i][4]);
	return 0;
}
