#include <iostream>  
#include <algorithm>  
using namespace std;  
int main()  
{  
    int num[11];
    for(int i=0;i<11;i++)num[i]=i+1;  
    do  
    {  
          for(int i=0;i<11;i++)cout<<num[i]<<" ";
          cout<<endl;
    }while(next_permutation(num,num+11));  
    return 0;  
}  