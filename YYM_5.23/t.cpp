#include <iostream>
using namespace std;
string s, fi;
const int MAXM=1010,MAXN=1010;
int M, N;            //M, N�ֱ��ʾ���Ҳ༯�ϵ�Ԫ������
int Map[MAXM][MAXN]; //�ڽӾ����ͼ
int p[MAXN];         //��¼��ǰ�Ҳ�Ԫ������Ӧ�����Ԫ��
bool vis[MAXN];      //��¼�Ҳ�Ԫ���Ƿ��ѱ����ʹ�
bool match(int i)
{
    for (int j = 1; j <= N; ++j)
        if (Map[i][j] && !vis[j]) //�б���δ����
        {
            vis[j] = true;                 //��¼״̬Ϊ���ʹ�
            if (p[j] == 0 || match(p[j])) //�������ƥ�䣬����ԭ��ƥ������Ԫ�ؿ����ҵ��µ�ƥ��
            {
                p[j] = i;    //��ǰ���Ԫ�س�Ϊ��ǰ�Ҳ�Ԫ�ص���ƥ��
                return true; //����ƥ��ɹ�
            }
        }
    return false; //ѭ����������δ�ҵ�ƥ�䣬����ƥ��ʧ��
}
int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= M; ++i)
    {
        memset(vis, 0, sizeof(vis)); //����vis����
        if (match(i))
            cnt++;
    }
    return cnt;
}

int main()
{
    s = "abcabcabc";
    fi = "abc";
    int t = s.find(fi,s.find(fi)+1);
    cout << t;
}