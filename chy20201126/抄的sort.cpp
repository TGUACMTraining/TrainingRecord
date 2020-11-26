#include <iostream> 
#include <algorithm> 
  
using namespace std; 
  
void show(int a[]) 
{ 
    for(int i = 0; i < 10; ++i) 
        cout << a[i] << " "; 
} 
  
int main() 
{ 
    int a[10]= {1, 5, 8, 9, 6, 7, 3, 4, 2, 0}; 
    cout << "\n 排序前数组为 : "; 
    show(a); 
  
    sort(a, a+10); 
  
    cout << "\n\n 排序后数组为 : "; 
    show(a); 
  
    return 0; 
  
}
