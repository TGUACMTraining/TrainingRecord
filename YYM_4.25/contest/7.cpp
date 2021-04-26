#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<ctime>
using namespace std;
int main(){
    int n;
    cin>>n;
    int zuida,zuixiao;
    int num1,num2;
    cin>>zuida;
    zuixiao=zuida;
    num1=num2=1;
    n--;
    while(n--){
        int cache;
        cin>>cache;
        if(cache>zuida){
            zuida=cache;
            num1=1;
        }else if(cache==zuida){
            num1++;
        }else if(cache<zuixiao){
            zuixiao=cache;
            num2=1;
        }else if(cache==zuixiao){
            num2++;
        }
    }
    cout<<zuixiao<<" "<<num2<<endl;
    cout<<zuida<<" "<<num1<<endl;
}