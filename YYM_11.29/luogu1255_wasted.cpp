#include<stdio.h>
#define length_of_array 1000
// #define dbg(x) {x;}
#define dbg(x)
class large_number{
    public:
        unsigned char arr[length_of_array]={0};
        int largest_index=0;
        int isundefined=1;
        large_number operator+(large_number b){
            large_number c;
            unsigned int max=10;
            int i;
            int j;
            for(i=0;i<=this->largest_index||i<=b.largest_index;i++){
                c.arr[i]+=this->arr[i]+b.arr[i];
                for(j=i;c.arr[j]/max;j++){
                    c.arr[j+1]+=c.arr[j]/max;
                    c.arr[j]%=max;
                }
            }
            i--;
            c.isundefined=0;
            dbg(
                printf("a:%d b:%d ",this->largest_index,b.largest_index);
                printf("%d\n",c.largest_index);
                printf("%d",c.arr[i+1]);
            )

            if (c.arr[i+1])c.largest_index=i+1;
            else c.largest_index=i;
            return c;
        }
        void print_large_number(void){
            for(int i=this->largest_index;i+1;i--){
                dbg(printf("%d\n",this->largest_index);)
                if(this->arr[i+1])
                printf("%lld",this->arr[i]);
                else
                printf("%lld",this->arr[i]);
            }
        }
};
large_number in;
large_number func(int find,large_number tried[]);
int main(){
    int a;
    in.arr[0]=1;
    in.isundefined=0;
    in.largest_index=0;
    large_number tried[5001];
    scanf("%d",&a);
    if(a==0){
        printf("0");
        return 0;
    }else
    {
        func(a+1,tried).print_large_number();
        return 0;
    }
}
large_number func(int find,large_number tried[]){
    if(find==1)return in;
    else if(find==2)return in;
    else return tried[find].isundefined==1?tried[find]=func(find-1,tried)+func(find-2,tried):tried[find]; 
}
