#include <stdio.h>
int elda(int a[],int n){
    int large=a[0];
    for(int i=0;i<n;i++){
        if (large<a[i]){
            large=a[i];
        }
    }
    return large;
}
int ceo_sort(int a[],int n,int k){
    int x[10];int y[n];
    for(int i=0;i<10;i++){ x[i]=0;}
    for(int i=0;i<n;i++){x[((a[i]/k)%10)]++;}
    for(int i=1;i<10;i++){x[i]+=x[i-1];}
    for(int i=n-1;i>=0;i--){y[x[((a[i]/k)%10)]-1]=a[i];
    x[((a[i]/k)%10)]--;
    }
    for(int i=0;i<n;i++){a[i]=y[i];}

}
int radio_sort(int a[],int n){
    int k=elda(a,n);
    for(int i=1;(k/i)>0;i=i*10){
        ceo_sort(a,n,i);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    radio_sort(a,n);
    for(int i=0;i<n;i++){printf("%d ",a[i]);}

}