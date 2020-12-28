void swap(int &a,int &b){//&可以对原值修改
    int c=a;
    a=b;
    b=c;
}
int main(){
    int a=1;
    int b=2;
    swap(a,b);
    return 0; 
}
