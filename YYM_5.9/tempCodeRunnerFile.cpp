int father[1024];
int findfather(int k){
    if(k==father[k])return k;
    return father[k]=father[father[k]];
}