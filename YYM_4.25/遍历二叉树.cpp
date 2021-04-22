#include<string>
#include<iostream>
#include<stack>
using namespace std;
string inorder,preorder;
string table="";
void dfs(string p,string i){//p为先序遍历，i为中序遍历。
    table+="| ";
    cout<<table<<"get:"<<p<<":"<<i<<endl;
	if(i.size()<=0)return;//判断是否还有字符。
	int root;
   	//寻找根。
	for(int j=0;j<i.size();j++){
		if(i[j]==p[0]){
			root=j;
		}
	}
	dfs(p.substr(1,root),i.substr(0,root));//左子树第一个为根，要从位置“1”开始取。
    table.erase(table.size()-2);
	dfs(p.substr(root+1),i.substr(root+1));//substr（root+1），取出从root+1这个位置开始往后所有字符。
	cout<<"\t\t"<<p[0]<<endl;//输出根。
    table.erase(table.size()-2);
    cout<<table<<"return"<<endl;
}
int main(){
	while(cin>>preorder>>inorder){//多组数据。
		dfs(preorder,inorder);
		cout<<endl;//注意，要换行。
	}
	
}