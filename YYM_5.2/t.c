#include<stdio.h>
#include<string.h>
int cnt = 0;
void f(char* s, int len)
{
	for (int i = 1; i < len-1; ++i) {
		while(s[i]==' '&&len>i+1) {
			for (int j = i; j < len - 1; ++j) {
				s[j] = s[j + 1];
			}
			--len;
			++cnt;
		}
	}
}
int main()
{
	char s[81];
	gets(s);
	int n = strlen(s);
	f(s, n);
	s[n - cnt] = '\0';
	printf("%s", s);
	printf("\n");
	for(int i=0;s[i];i++){
		printf("%d ",s[i]);
	}
}
