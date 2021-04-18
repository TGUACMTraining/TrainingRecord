#include<iostream>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
struct dot
{
    int x:4,y:4;
};
struct data{
    string state ;
    int from;
    char ope;
    dot E;
}q[(int)4e5];
int main(){
    string a="123456789";
    map<string,int>m;
    int t;
    while(next_permutation(a.begin(),a.end()))m[a]=t++;
    getchar();
    cout<<t<<endl;
}