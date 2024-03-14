#include <stdio.h>
int swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int mh(int a[],int n,int i){
    int l=2*i+1;
    int r=2*i+2;
    int larg=i;
    if(l<n && a[l]>a[larg]){larg=l;}
    if(r<n && a[r]>a[larg]){larg=r;}
    if(larg!=i){
        swap(&a[i],&a[larg]);
        mh(a,n,larg);
    }
}
void heapsort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        mh(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&a[0],&a[i]);
        mh(a,i,0);
    }
}
int main(){
    int n;
    scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){scanf("%d",&a[i]);}
  heapsort(a,n);
  for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
}