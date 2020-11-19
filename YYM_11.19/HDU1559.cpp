#include<stdio.h>
int arr[1000][1000];
int shaddow[1000][1000];
int m,n,x,y;
int main(){
    int last;
    int question;
    scanf("%d",&question);
    while(question--)
    {
        scanf("%d%d",&m,&n);
        scanf("%d%d",&x,&y);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
            
        shaddow[0][0]=arr[0][0];
        for(int i=1;i<m;i++){
            shaddow[i][0]=shaddow[i-1][0]+arr[i][0];
        }
        for(int j=1;j<n;j++){
            shaddow[0][j]=shaddow[0][j-1]+arr[0][j];
        }   
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                shaddow[i][j]=arr[i][j]+shaddow[i-1][j]+shaddow[i][j-1]-shaddow[i-1][j-1];
            }
        }
   
        last=shaddow[x-1][y-1];
        int cache;
        for(int i=x;i<m;i++){
            cache=shaddow[i][y-1]-shaddow[i-x][y-1];
            last=cache>last?cache:last;
        }
        for(int j=y;j<n;j++){
            cache=shaddow[x-1][j]-shaddow[x-1][j-y];
            last=cache>last?cache:last;
        }
        for(int i=x;i<m;i++){
            for(int j=y;j<n;j++){
                cache=shaddow[i][j]-shaddow[i-x][j]-shaddow[i][j-y]+shaddow[i-x][j-y];
                last=cache>last?cache:last;
            }
        }
        
        printf("%d\n",last);
    }
    return 0;
}