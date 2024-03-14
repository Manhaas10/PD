#include <stdio.h>
int magic(int a[],int n,int k){
    int l=0;
    int r=n-1;
     for(;l<=r;){
       int m=(r+l)/2;
       if(a[m]==k){return m;}
       else{
        if(a[l]<=a[m]){
            (a[m]>k && k>=a[l])?(r=m-1):(l=m+1);
            }
        else{
            (a[m]>k&&k>=a[r])?(l=m+1):(r=m-1);
            }
            }
            }
return -1;}
int main(){
  int n,b;
    scanf("%d\n",&n);
    int luffy[n];
    for(int i=0;i<n;i++){
        scanf("%d",&luffy[i]);}
    scanf("%d",&b);
    printf("%d",magic(luffy,n,b));
    return 1;
    }
