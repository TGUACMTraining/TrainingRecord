
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
 
map<string,string> m;
 
int main()
{
    char str[15],a[15],b[15];
    string s;
    while(gets(str)&&str[0]!='\0')
    {
        sscanf(str,"%s%s",a,b);
        m[b]=a;
    }
    while(cin>>s)
    {
        if(m[s].size()) 
              cout<<m[s]<<endl;
        else cout<<"eh"<<endl;
    }
    return 0;
}