#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string.h>
#include<sstream>
#include<cmath>
#define DGT 10000
using namespace std;

class cal					//高精
{
public:
	int pn;					//pn=1 负数
	char* num;				//从0开始
	int digit;				//0代表0
public:
	cal& operator = (const cal& t)
	{
		if (this != &t)
		{
			if (num != NULL)
			{
				delete[] num;
				num = NULL;
			}
			num = new char[DGT]();
			digit = t.digit;
			pn = t.pn;
			memcpy(num, t.num, t.digit * sizeof(char));
		}
		return *this;
	}
	static bool absolute_cmp(const cal* a, const cal* b)
	{
		if (a->digit < b->digit) {
			return 1;
		}
		for (int i = a->digit - 1; i >= 0; i--)
		{
			if (a->num[i] > b->num[i]) {
				return 0;
			}
			else if (a->num[i] < b->num[i]) {
				return 1;
			}
		}
		return 0;
	}
	cal()
	{
		pn = 0;
		num = new char[DGT]();
		digit = 0;
	}
	virtual ~cal()
	{
		delete[] num;
	}
	cal& operator =(const char* s)			//最重要的输入，其他类型的基础 
	{
		//深拷贝
		if (num != NULL)
		{
			delete[] num;
			num = NULL;
		}
		num = new char[DGT]();
		//负数判断 
		int p = 0;
		if (s[0] == '-') {
			pn = 1; p = 1;
		}
		else {
			pn = 0;//p = 0 自然确立
		}
		while (s[p] == 48)p++;			//去除前导0
		digit = strlen(s + p);
		//倒置写入 
		for (int i = 0; i < digit; i++)
		{
			num[i] = s[digit - i - (1 ^ pn)] - 48;
		}
		return *this;
	}
	void operator =(int t)
	{
		char temp[10];
		sprintf(temp, "%d", t);
		*this = temp;
	}
	cal(int t)
	{
		num = new char[DGT]();
		char temp[10];
		sprintf(temp, "%d", t);
		*this = temp;
	}
	/*~cal()
	{
		delete[] this->num;
	}*/
	const char* c_str()
	{
		static char temp[DGT + 1] = "-";
		if (!digit) {
			temp[0] = '0';
			return temp;
		}
		for (int i = 1; i <= digit; i++)
		{
			temp[i] = num[digit - i] + 48;
		}
		if (pn)return temp;
		else return temp + 1;
	}
};
static cal caltemp;

const cal& operator +(const cal& a, const cal& b)
{
	caltemp = 0;
	const cal* l, * r;					//l>r
	if (cal::absolute_cmp(&a, &b)) {
		l = &b;
		r = &a;
	}
	else {
		l = &a;
		r = &b;
	}
	if (!r->digit)return *l;				//0
	for (int i = 0; i < l->digit; i++)
	{
		caltemp.num[i] += l->num[i] + r->num[i] - 2 * (r->pn ^ l->pn) * r->num[i];
		caltemp.num[i + 1]--;
		caltemp.num[i + 1] += (caltemp.num[i] + 10) / 10;
		caltemp.num[i] %= 10;
	}
	caltemp.pn = l->pn;
	caltemp.digit = l->digit + 1;
	while (caltemp.digit > 0 && !caltemp.num[caltemp.digit - 1])caltemp.digit--;
	return caltemp;
}
const cal& operator * (const cal& a, const cal& b)
{
	caltemp = 0;
	for (int i = 0; i < a.digit; i++)
	{
		for (int j = 0; j < b.digit; j++)
		{
			caltemp.num[i + j] += a.num[i] * b.num[j];
			if (caltemp.num[i + j] > 9) {
				caltemp.num[i + j + 1] += caltemp.num[i + j] / 10;
				caltemp.num[i + j] %= 10;
			}
		}
	}
	caltemp.pn = a.pn ^ b.pn;
	caltemp.digit = a.digit + b.digit;
	while (caltemp.digit > 0 && !caltemp.num[caltemp.digit - 1])caltemp.digit--;

	return caltemp;
}
const cal& xmul(const cal& a, const cal& b)
{
	caltemp = 0;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			caltemp.num[i + j] += a.num[i] * b.num[j];
			if (caltemp.num[i + j] > 9) {
				caltemp.num[i + j + 1] += caltemp.num[i + j] / 10;
				caltemp.num[i + j] %= 10;
			}
		}
	}
	caltemp.pn = a.pn ^ b.pn;
	caltemp.digit = a.digit + b.digit;
	while (caltemp.digit > 0 && !caltemp.num[caltemp.digit - 1])caltemp.digit--;

	return caltemp;
}
cal ans = 1, powup = 2, ct = -1;
void ppow(int p)
{
	if (p & 1) {
		ans = ans * powup;
	}
	p >>= 1;
	while (p)
	{
		powup = xmul(powup, powup);
		if (p & 1) {
			ans = xmul(ans, powup);
		}
		p >>= 1;
	}
}
int main()
{
	int p,len;
	scanf("%d", &p);
	len = p* log10(2) + 1;
	ppow(p);
	ans = ans + ct;
	printf("%d\n", len);
	for (int i = 499; i >= 0; i--)
	{
		printf("%d", ans.num[i]);
		if (i % 50 == 0)printf("\n");
	}
	return 0;
}