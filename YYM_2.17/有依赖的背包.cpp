#include<iostream>

#include<vector>

using namespace std;

int f[110][110];//f[u][j]表示选择以u为子树的物品，在体积和不超过容量j时所获得的最大价值

vector<int>a[110];//动态数组存储邻接点

int v[110],w[110];

int n,m,root;



int dfs(int u)

{
  
    printf("进入节点%d\n",u);

  for(int i=v[u];i<=m;i++) 

f[u][i]=w[u]; //选u，体积不能小于v[u] 

  for(int i=0;i<a[u].size();i++) {//物品，每个儿子是一组物品 

    int s=a[u][i]; 
    printf("\t发现子节点：%d\n",s);

    dfs(s); //递归儿子s
    

    for(int j=m;j>=v[u];j--){ //体积，小于v[u]无法选择以u为子树的物品 

      for(int k=0;k<=j-v[u];k++){ //决策，每种决策对应一个打包的物品，可能包含多个的子孙物品的组合。 

        f[u][j]=max(f[u][j],f[u][j-k]+f[s][k]);

      }

    }

  }

}



int main()

{

  cin>>n>>m;

  for(int i=1;i<=n;i++){

    int p;

    cin>>v[i]>>w[i]>>p;

    if(p==-1)

      root=i;

    else

a[p].push_back(i);

  }

  dfs(root);

  cout<<f[root][m];

  return 0;

}

/*样例输入 

5 6

4 4 3

2 2 3

2 3 -1

1 3 2

1 1 2



*/ 

/*
来自 ：董晓算法（bilibili）
*/