 #include<iostream>
 #include<string.h>
 
 using namespace std;
 
 char n1[2002], n2[2002];
 int a[10000],b[10000],c[100000];
 

/*string add(string str1,string str2)
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    if(len1<len2)
    {
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}*/
 
 
 int main()
 {
	
	
	cin >> n1; 
	cin >> n2;
	int p;
	int s1=strlen(n1),s2=strlen(n2);
	
	
	for(int i = 0,j=s1-1;i<s1;i++,j--) a[i]=n1[j] - '0';
	
	for(int i=0,j=s2-1;i<s2;i++,j--)b[i]=n2[j]-'0';
	for(int i=0;i<8;i++) cout<<"a"<<a[i]<<'\n';
	for(int i=0;i<s1;i++)
		{
			for(int j=0;j<s2;j++)
			{
				c[i+j]+=a[i]*b[j];
				printf("c[%d]=%d\n",i+j,c[i+j]);
			}
		}
for(int i =0;i<s1+s2;i++)
{
	int j=c[i];
	if(j>=10)
	{
		c[i]=j%10;
		c[i+1]+=j/10;
	}
}	for(int i=s1+s2+10;i>=0;i--)
{
	if(c[i]!=0)
	{
		p=i;
		break;
	}
}
for(;p>=0;p--)
{
	cout << c[p];
}
  } 
