#include <stdio.h>
int luffy(int n){
   static int i=1;
    if (i<=n){
        printf("%d ",i);
        i++;
    return luffy(n);}
    return 1;}

int main(){
    int n;
    scanf("%d",&n);
    if(n>0 && n<=1000){
    luffy(n);
}
 return 0;
}