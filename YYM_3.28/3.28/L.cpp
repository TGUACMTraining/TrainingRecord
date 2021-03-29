    #include<iostream>
    #include<string>
    #include<cstring>
    using namespace std;
    int main(){
        char str[(int)1e6];
        int n;
        cin>>n;
        getchar();
        while (n--)
        {
            int cnt=0;
            fgets(str,(int)1e6,stdin);
            int len=strlen(str);
            for(int i=0;i<len;i++){

                if(str[i]<0)cnt++;
            }
            cout<<cnt/2<<endl;
        }
        
    }