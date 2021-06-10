    #include<iostream>  
    #include<cstring>
    using namespace std;
    int kmp[(int)1e6+10];
    char a[(int)1e6+10];
    char b[(int)1e6+10];
    int la,lb;
    void build(){
        int j=0;
        for(int i=2;i<=lb;i++){
            while(j&&b[j+1]!=b[i])j=kmp[j];
            if(b[i]==b[j+1])j++;
            kmp[i]=j;
        }
    }
    void find(){
        int j=0;
        for(int i=1;i<=la;i++){
            while(j&&b[j+1]!=a[i])j=kmp[j];
            if(a[i]==b[j+1])j++;
            if(j==lb){
                printf("%d\n",i-j+1);
                j=kmp[j];
            }
        }
    }
    int main(){
        scanf("%s%s",a+1,b+1);
        la=strlen(a+1);
        lb=strlen(b+1);
        build();
        find();
        for(int i=1;i<=lb;i++){
            printf("%d ",kmp[i]);
        }
        printf("\n");
    }