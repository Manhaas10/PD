#include <stdio.h>

void shambles(int *x, int *y,int* k)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    (*k)--;
}
 
void finale(int a[], int n,int* k)
{
    int i, j, min_idx,max_idx;
 
    for (i = 0; i < n-1; i++)
    {   if(i%2==0){
        min_idx = i;
        for (j = i+1; j < n; j++){
          if (a[j] < a[min_idx]){
            min_idx = j;}}
            if(min_idx != i && *k>0)
            shambles(&a[min_idx], &a[i],k);
            else if(*k==0) break;}
        else{
            max_idx=n-i;
            for(j=n-1-i;j>=i;j--){
             if (a[j] > a[max_idx]){
                max_idx=j;}}
                if(max_idx != i && *k>0)
            shambles(&a[max_idx], &a[i],k);
            else if(*k==0) break;
        }
    }
}
int main(){
    int n,k;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    scanf("%d",&k);
    finale(a,n,&k);
    for(int i=0;i<n;i++){printf("%d ",a[i]);}
    return 0;
}