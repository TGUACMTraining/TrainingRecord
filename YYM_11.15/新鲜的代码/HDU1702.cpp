    #include<stdio.h>

    int main(){
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int q;
            char fi[5];
            char cache[4];
            int all[100];
            int left,right;
            left=right=0;
            scanf("%d",&q);
            scanf(" %s",fi);
            switch(fi[2]){
                case 'F':
                    {
                        while(q--)
                        {
                            scanf(" %s",cache);
                            switch(cache[0]){
                                case 'I':
                                {
                                    scanf("%d",&all[right]);
                                    right++;
                                }
                                break;
                                case 'O':
                                {
                                    if(left>right-1){printf("None\n");break;}
                                    printf("%d\n",all[left]);
                                    left++;
                                }
                                break;
                            };
                        }
                    }
                break;
                case 'L':
                    {
                        while(q--)
                        {
                            scanf(" %s",cache);
                            switch(cache[0]){
                                case 'I':
                                {
                                    scanf("%d",&all[right]);
                                    right++;
                                }
                                break;
                                case 'O':
                                {
                                    right--;
                                    if(right<0){printf("None\n");break;}
                                    printf("%d\n",all[right]);
                                }
                                break;
                            };
                        }
                    }
                break;
            };
        }
        return 0;
    }