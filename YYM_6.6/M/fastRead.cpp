#include<cstdio>
char*p;
const int caches_input=20e6;
template<class T> inline void read(register T &x){
    int flag=1;x=0;
    while(!isdigit(*p))(*p++)=='-'&&(flag=-1);
    while(isdigit(*p))x=(x<<3)+(x<<1)+(*p++&15);//�˴�ע��&�������ڣ�Ȼ��"<<"Ҫ������
    x*=flag;
}
int main(){
    p=new char[caches_input];
    fread(p,1,caches_input,stdin);
}