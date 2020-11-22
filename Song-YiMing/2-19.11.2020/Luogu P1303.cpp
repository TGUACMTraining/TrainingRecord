#include<cstdio>
#include<string.h>
#include<sstream>
#define DGT 6666
using namespace std;

class cal					//高精乘 
{
public:
	bool pn;			//pn=1 负数
	char num[DGT];	 
	int digit;
	void operator = (cal t)
	{
		this->digit = t.digit;
		this->pn = t.pn;
		memcpy(this->num, t.num, sizeof(t.num));
	}
	cal()
	{
		pn = 0;
		memset(num, 0, sizeof(num));
		digit = 1;
	}
	cal(const char* s)			//最重要的输入，其他类型的基础 
	{
		memset(num, 0, sizeof(num));
		char temp[DGT]="";
		//负数判断 
		int p=0;
		if(s[0]=='-'){
			pn = 1;
			p = 1;
		}
		else{
			pn = 0;
		}
		while(s[p] == 48)p++;
		sscanf(s+p, "%s", temp);
		//倒置 
		for(int i=0,j=strlen(temp)-1;i<j;i++,j--)
		{
			swap(temp[i],temp[j]);
		}
		//写入 
		for(int i=0;i<strlen(temp);i++)
		{
			num[i]=temp[i]-48;
		}
		digit=strlen(temp);
	}
	cal(int t)
	{
		char temp[DGT] = "";
		sprintf(temp, "%d", t);
		*this = temp;
	}
	cal(long long t)
	{
		char temp[DGT]="";
		sprintf(temp, "%lld", t);
		*this=temp;
	}
	cal operator * (const cal a)
	{
		cal temp = 0;
		for(int i = 0;i < a.digit; i++)
		{
			for(int j = 0; j < this->digit; j++)
			{
				temp.num[i+j] += a.num[i] * this->num[j];
				if(temp.num[i+j] > 9){
					temp.num[i+j+1] += temp.num[i+j] / 10;
					temp.num[i+j] %= 10;
				}
			}
		}
		temp.pn=a.pn ^ this->pn;  
		temp.digit = a.digit + this->digit;
		while(temp.num[temp.digit]==0 && temp.digit)
			temp.digit--;
		temp.digit++;
		return temp;
	}
	const char* c_str()
	{
		static char temp[DGT+1]="-";
		if(!digit){
			temp[0]='0';
			return temp;
		}
		for(int i=1;i<=digit;i++)
		{
			temp[i]=num[digit-i]+48;
		}
		if(pn)return temp;
		else return temp+1;
	}
	
};
int main()
{
	cal num[3];
	for(int i=1;i<=2;i++)
	{
		char c[DGT];
		scanf("%s",c);
		num[i] = c;
	}
	num[0] = num[1] * num[2];
	printf("%s", num[0].c_str());
	return 0;
}

