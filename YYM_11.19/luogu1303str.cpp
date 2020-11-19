#include<stdio.h>
#include<cstring>
//#define debug
#ifdef debug
#define debpri printf
#else 
#define debpri //
#endif
int main(){
    char a[2001]={0};
    char b[2001]={0};
    int c[4002]={0};
    int alast,blast;
    scanf("%s",a);
    scanf("%s",b);
    alast=strlen(a);
    blast=strlen(b);
    debpri("%d",alast);
    
    {
        int i,j;
        for(i=0,j=--alast;i<j;i++,j--){
            a[i]-='0';
            a[j]-='0';
        }
        if(i==j)a[i]-='0';
        for(i=0,j=--blast;i<j;i++,j--){
            b[i]-='0';
            b[j]-='0';
        }
        if(i==j)b[i]-='0';
    }
    {
        int acon=0,bcon=0;
        int aindex;
        int cache;
        for(;blast>=0;blast--,bcon++){
            for(acon=0,aindex=alast;aindex>=0;aindex--,acon++){
                c[acon+bcon]+=a[aindex]*b[blast];
                for(int t=0;c[acon+bcon+t]/10;t++)
                {
                    c[acon+bcon+t+1]+=c[acon+bcon+t]/10;
                    c[acon+bcon+t]%=10;
                }
                // int q=c[acon+bcon]+=cache;
                // c[acon+bcon]/=10;
                // for(int t=0;q;q/=10,t++)
                // {c[acon+bcon+t]+=q%10;}
                //c[acon+bcon+1]+=cache/10+c[acon+bcon]/10;
                //c[acon+bcon]%=10;
            
            }
        }
        //strrev(c);想多了，c++压根没有字符串反转。。
        int i=4001;
        while(!c[i]&&i>=0)i--;
        if(i==-1)printf("0");    
        for(;i>=0;i--){
        printf("%d",c[i]);
        }
                
    debpri("here");
        
        
    }
    return 0;

}
