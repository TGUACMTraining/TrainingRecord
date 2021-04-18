#include<iostream>
using namespace std;
int main(){
    freopen("D:\\mass_organizations\\ACM\\git_github\\ACMtraining\\TrainingRecord\\YYM_4.4\\4.4\\test.txt","r",stdin);
    freopen("D:\\mass_organizations\\ACM\\git_github\\ACMtraining\\TrainingRecord\\YYM_4.4\\4.4\\test2.txt","w",stdout);
    char c;
    while(~scanf("%c",&c)){
        switch (c)
        {
        case 'b':
            cout<<1;
            break;
        case 'w':
            cout<<0;
            break;
        default:
            cout<<c;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
}