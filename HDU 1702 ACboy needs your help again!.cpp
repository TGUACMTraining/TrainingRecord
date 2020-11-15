#include<cstdio>
#include<iostream>
#include<stack>
#include<queue>
#include<string.h> 
using namespace std;
int a[1000]; 
int main()
{
    stack<int> st;
    queue<int> que;
    int m, i, j, b, tag1, tag2;
    char s[10], d[5]; 
    scanf("%d", &m);
    for(i = 0; i<m; i++)
    {
        tag1 = tag2 = 0; 
        scanf("%d%s", &a[i],s);
        if(strcmp(s, "FIFO") == 0)    //    队列 
        {
            for(j = 0; j<a[i]; j++)
            {
                memset(d, 0, sizeof(d)); 
                scanf("%s", d);
                if(strcmp(d, "IN") == 0)
                {
                    scanf("%d", &b); 
                    que.push(b); 
                    tag1++;
                //    printf("tag1* = %d\n", tag1); 
                }
                else if(strcmp(d, "OUT") == 0)
                {
                    if(!que.empty() && tag1 > 0)
                    {
                            printf("%d\n", que.front());
                            que.pop(); 
                            tag1--;
                    }  
                    else if(tag1 <= 0 || que.empty()) 
                    printf("None\n"); 
                } 
            } 
        } 
        else if (s, "FILO")        //    栈 
        {
            for(j = 0; j<a[i]; j++)
            {
                scanf("%s", d);
                if(strcmp(d, "IN") == 0)
                {
                    scanf("%d", &b); 
                    st.push(b); 
                    tag2++;
                }
                else if(strcmp(d, "OUT") == 0)
                {
                    if(!st.empty() && tag2 > 0)
                    {
                        printf("%d\n", st.top());
                        st.pop();
                            tag2--;
                    } 
                    else if(tag2 <= 0 || st.empty()) 
                    printf("None\n"); 
                } 
            } 
        } 
    } 
    return 0; 
}
