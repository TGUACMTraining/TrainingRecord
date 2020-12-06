#include<stdio.h>
#define length_of_array 10
// #define dbg(x) {x;}
#define dbg(x)
class large_number{
    public:
        unsigned long long arr[length_of_array]={0};
        int largest_index=0;
        int isundefined=1;
        large_number operator+(large_number b){
            large_number c;
            unsigned long long max=1e1;
            int i;
            for(i=0;i<=this->largest_index||i<=b.largest_index;i++){
                c.arr[i]=this->arr[i]+b.arr[i];
                c.arr[i+1]+=c.arr[i]/max;
                c.arr[i]%=max;
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
                printf("%01lld",this->arr[i]);
                else
                printf("%lld",this->arr[i]);
            }
        }
};
large_number in;
int main(){
   large_number a;
   large_number b;
   a.arr[0]=10;
   a.arr[0]-=1;
   a.largest_index=0;
   a.isundefined=0;
   b.arr[0]=1;
   b.largest_index=0;
   b.isundefined=0;
   (a+b).print_large_number();
   printf("\n%d",(a+b).largest_index);
   a.arr[0]=10;
   printf("\n");
   a.print_large_number();
   return 0;
}
