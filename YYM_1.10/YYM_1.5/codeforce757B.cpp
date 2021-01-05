#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MAXL 1000000
int prime[MAXN];
bool check[MAXL];
void pri(){
    int  n,count;
    n=100000;
        memset(check, 0, sizeof(check));
        count = 0;
        for (int i = 2; i <= n; i++)
        {
            if (!check[i])	
                prime[count++] = i;	
            for (int j = 0; j < count; j++)	
            {
                if (i*prime[j] > MAXL)
                    break; 
                check[i*prime[j]] = 1; 
                if ( (i%prime[j]) == 0 )
                    break; 
            }
        }
}
int main(){
    int n;
    int cache;
    cin>>n;
    int t;
    int count[100000]={0};
    pri();
    for(int i=0;i<n;i++){
        cin>>cache;
        if(check[cache]==0){
            count[cache]++;
            continue;
        }
        t=(int )sqrt(cache)+1;
        set<int >breakup;
        for(int j=0;cache!=1;j++){
            while(cache%prime[j]==0){
                breakup.insert(prime[j]);
                cache/=prime[j];
            }
        }
        for(set<int >::iterator index=breakup.begin();index!=breakup.end();index++){
            count[*index]++;
        }
    }
    int max=0;
    count[1]=1;
    for(int i=0;i<100000;i++){
        if(max<count[i])max=count[i];
    }
    if(!max)max=1;
    cout<<max<<endl;
    return 0;
}