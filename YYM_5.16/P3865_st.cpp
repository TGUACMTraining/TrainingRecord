#include<iostream>
#include<cmath>
using namespace std;
int st[(int)1e5][30];
int n,m;
inline int s(int k){
    return 1<<k;
}
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        st[i][0]=read();
    }
    for(int j=1;j<30;j++){
        for(int i=1;i+s(j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+s(j-1)][j-1]);
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        a=read(),b=read();
        int k=log2(b-a+1);
        printf("%d\n",max(st[a][k],st[b+1-s(k)][k]));
    }
}