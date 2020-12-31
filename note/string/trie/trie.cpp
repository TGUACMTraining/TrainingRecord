#include<cstring>
const int max_depth=100;//所有链长度之和
const int chars=30;//根据字符集大小判断
int tree[max_depth][chars]={0};
int tot=0;
void insert_(char*str){
    int len=strlen(str);
    int root=0;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(!tree[root][id])tree[root][id]=++tot;
        root=tree[root][id];
    }
}
int find_(char*str){
    int len=strlen(str);
    int root=0;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(!tree[root][id])return 0;
        root=tree[root][id];
    }
    return root;//返回在树中的位置
}
int main(){
    return 0;
}