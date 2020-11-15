#include<iostream>
#include<sstream> 
#include<queue>
#include<stack>
#include<string> 
#include<stdio.h>



using namespace std;
int main()
{
	int n;string ss1,ss2;
	cin >> n;
	queue<int> r ;queue<string> rs;queue<string> sr;
	stack<int> s; 
	for(int i=0;i < n;i++)
	{
		
		int m;
		cin >> m;
		string a;
		cin >> a;
		
		if(a    == "FIFO")
		{
			
			for(int ii = 0; ii < m;ii ++)
			{
				
				string a1;
				cin >> a1;
				
				if(a1 == "IN")
				{
					int aa;
					cin >> aa;
					r.push(aa);
					
					
								
				}
				else if(a1 == "OUT")
				{
					
					if(!r.empty())
					{   stringstream stream1;
						stream1 << r.front();
						stream1 >> ss1;
						rs.push(ss1);
						
						
						
					
									
						r.pop();
				
				}
				else
					{
						rs.push("None");
					}
				}
				
				
			}
			
				for(;!rs.empty();)
				{
					
								
								string xxx = rs.front();
								printf("%s\n",xxx.c_str());
					rs.pop();
				}
			for(;!r.empty();)
			{
				r.pop();
			}
		}
		else if(a == "FILO")
		{
			for(int ia = 0;ia < m;ia ++)	
			{
			
				
				string s1;
				cin >> s1;
				
				if(s1 == "IN")
				{
					int ss;
					cin >> ss;
					s.push(ss);
					
					
			
			
				}
				else if(s1 == "OUT")
				{
					if(!s.empty()){
							stringstream stream2;
							stream2 << s.top();
						stream2 >> ss2;
					
					
				
					sr.push(ss2);					
									s.pop();								
				}
				else	
								{
						sr.push("None");
					
				}
		}
		
			
		}for(;!sr.empty();)
				{
					string xx = sr.front();
					printf("%s\n",xx.c_str());
					sr.pop();
				}
		
				
				
				
				for(;!s.empty();)
				{
					s.pop();
				}
		}
}}
	
 
