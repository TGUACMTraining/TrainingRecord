#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;
inline int add(char c){
    if (c=='0') return 0;
    if(c>='1'&&c<='9')return c-'1'+1;
    switch (c)
    {
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;

    }
}
char A[20],B[20];
long long a,b;
long long transform(char * t){
    long long res=0;
    int i=0;
    int flag=1;
    if(t[0]=='-'){i++;flag=-1;}
    else if(t[0]=='+'){i++;}
    for(;t[i];i++){
        res*=16;
        res+=add(t[i]);
    }
    res*=flag;
    return res;
}
int main(){
while(~scanf("%s%s",A,B)){
    a=transform(A);
    b=transform(B);
    long long c=a+b;
    stack<int>res;
    if(c<0){cout<<"-";c=-c;}
    if(c==0)cout<<"0";
    while(c){
        res.push(c%16);
        c/=16;
    }
    char arr[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(!res.empty()){
        cout<<arr[res.top()];
        res.pop();
    }cout<<endl;
}
}