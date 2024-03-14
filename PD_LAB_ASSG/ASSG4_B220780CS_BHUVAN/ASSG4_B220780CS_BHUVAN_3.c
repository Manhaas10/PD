#include <stdio.h>
int shambles(char* a,char* b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
int divide(char a[],int f,int l){
    char key=a[l];
    int i=f-1;
    for(int j=f;j<l;j++){
        if(a[j]>key){
            i++;
            shambles(&a[i],&a[j]);
        }
    }
    shambles(&a[i+1],&a[l]);
    return i+1;
}
int fast_sort(char a[],int f,int l){
   if(f<l){
    int p=divide(a,f,l);
    fast_sort(a,f,p-1);
    fast_sort(a,p+1,l);    
   }

}
int main(){
    int n;
    scanf("%d",&n);
    char a[n];
    for(int i=0;i<n;i++){scanf(" %c",&a[i]);}
    fast_sort(a,0,n-1);
    for(int i=0;i<n;i++){printf("%c ",a[i]);}

}