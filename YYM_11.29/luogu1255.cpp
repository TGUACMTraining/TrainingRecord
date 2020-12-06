#include<stdio.h>
// #define debug
#ifdef debug
#define dbg(x) {x;}
#else 
#define dbg(x)
#endif
#define length_of_char 300
#define tried(x) tried[length_of_char*(x)]
char* func(int find,char * tried);
void plus(char* a,char*b,char *c);

int main(){
    int a;
    char tried[5001*length_of_char]={0};
    tried[0]='0';
    tried(1)='1';
    tried(2)='2';
    dbg(
        printf("p=%p\n",tried);
    )
    scanf("%d",&a);
    if(a==0){
        printf("0");
        return 0;
    }else
    {char*p=func(a,tried);int i=0;for(;p[i];i++);i--;for(;p[i];i--)printf("%c",p[i]);return 0;}
}
char* func(int find,char * tried){
    dbg(
        printf("p=%p\n",tried);
    )
    if(tried(find)){
        dbg(printf("%d defined\n",find);)
        return &tried(find);
    }else{
        dbg(printf("%d undefined\n",find))
        plus(func(find-1,tried),func(find-2,tried),&tried(find));
        return &tried(find);
    }
}
void plus(char* a,char*b,char *c){
    int i;
    int j;
    dbg(
        printf("a=%s\n",a);
        printf("ap=%p\n",a);
        printf("a=%c\n",a[0]);
        printf("b=%s\n",b);
        printf("bp=%p\n",b);
        printf("b=%c\n",b[0]);
        printf("c=%s\n",c);
        printf("cp=%p\n",c);
        printf("c=%c\n",c[0]);
    )
    
    for(i=0;a[i]&&b[i];i++){
        int x=a[i]-'0',y=b[i]-'0';
        c[i]+=x+y;
        dbg(
            printf("c[i=%d] %d\t",i,c[i]);
        )
        for(j=i;(c[j])/10;j++){
            dbg(
            printf("c[j=%d] %d\t",j,c[j]);
            )
            c[j+1]+=(c[j])/10;
            c[j]%=10;
        }
    }
    for(;a[i]||b[i];i++){
        c[i]+=a[i]+b[i]-'0';
    }
    i--;
    i=i<j?j:i;
    for(;i+1;i--){
        c[i]+='0';
    }
    dbg(
        // printf("%s",c);
    )
}