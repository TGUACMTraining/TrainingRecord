#include<bits/stdc++.h> 
using namespace std;
char a[10005];
int pdzm(char c)//�ж��Ƿ���ĸ 
{
    if(c>='a'&&c<='z')
        return 1;
    if(c>='A'&&c<='Z')
        return 1;
    return 0;
}
int pdyy(char c)//�ж��Ƿ�Ԫ�� 
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return 1;
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return 1;
    return 0;
}
int main()
{
    while(gets(a))
    {
        int s=0,t=0;//s����ǰ��ĸ,t�����ʳ���. 
        while(a[s])
            if(!pdzm(a[s])) 
            {
                cout<<a[s++]; 
                t=s;
            }
            //������ĸ�������. 
            else 
                if(pdzm(a[t]))
                    t++;
            //����ĸ�ͼ�¼���� 
            else //����Ǹ�����ͷ�ѵ��ʵĿ�ͷ�ŵ����Ȼ������ay��׺���ɡ�
            {
                if(!pdyy(a[s]))
                {
                    for(int i=s+1;i<t;i++)cout<<a[i];
                    cout<<a[s];
                }
                else 
                    for(int i=s;i<t;i++)
                        cout<<a[i];
                cout<<"ay";
                s=t;
            }
        cout<<endl;
    }
    return 0;
}
