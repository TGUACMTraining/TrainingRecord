#include<iostream>
using namespace std;
int arr[60];
char trans[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int tail;
int main()
{
    int N,R;
    while(cin>>N>>R){
        int flag=1;
        if(N<0){flag=-1;N=-N;}
        tail=0;
        if(flag==0){cout<<0<<endl;continue;}
        while(N){
            arr[tail++]= N%R;
            N/=R;
        }
        if(flag==-1)cout<<'-';
        tail--;
        while (tail!=-1)
        {
            cout<<trans[arr[tail]];
            tail--;
        }
        cout<<endl;
    }
}