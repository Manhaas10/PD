#include <stdio.h>
#include <math.h>

int fact(int n){

    int p=1;
    for(int i=1;i<=n;i++){
        p=p*i;}
    return p;}

int main(){
    int n;
    float x;
    scanf("%f\n",&x);
    if (x>=0&&x<=360){
       scanf("%d",&n);
    if(n>=0 && n<=1000){
    x=x*(3.1415/180);
    float sum=0;
    int p;
    int j=0;
   for(int i=1;i<=n;i+=2){
    p=pow(-1,j);
     sum+=p*(pow(x,i))/fact(i);
        j++;
        }
    printf("%0.4f",sum);

}}
 return 0;
}