#include <stdio.h>
int ace(int a[],int n){
    int i=1;
    int largest=a[0];
    while(i<n){
        if (largest<a[i]){
            largest=a[i];
        }i++;
    }
    return largest;

}
int main(){
    int n,i=0;
    scanf("%d",&n);
    int a[n];
    while(i<n){
        scanf("%d",&a[i]);
        i++;
    }
    printf("%d",ace(a,n));
    return 0;
}